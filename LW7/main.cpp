#include "npc.hpp"
#include "Factory.hpp"
#include "Knight.hpp"
#include "SlaveTrader.hpp"
#include "Squirrel.hpp"
#include <sstream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;
std::mutex print_mutex;

void save(const set_t& array, const std::string& filename) {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto& n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string& filename) {
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(Factory::CreateNPC(is));
        is.close();
    } else
        throw std::runtime_error("loading from file error");
    return result;
}

std::ostream& operator<<(std::ostream& os, const set_t& array) {
    for (auto& n : array)
        n->print();
    return os;
}

struct print : std::stringstream {
    ~print() {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager final {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager& get() {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent&& event) {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()(void* args) {
        auto time = (std::chrono::seconds*) args;
        auto start = std::chrono::steady_clock::now();
        while (true) {
            std::optional<FightEvent> event;
            {
                std::lock_guard<std::shared_mutex> lock(mtx);
                if (!events.empty()) {
                    event = events.back();
                    events.pop();
                }
            }
            if (event) {
                if (
                    event->attacker->is_alive() &&
                    event->defender->is_alive() && 
                    event->defender->accept(event->attacker) &&
                    (event->attacker->throw_dice() > event->defender->throw_dice())
                ) {
                    event->defender->must_die();
                }

            } else {
                std::this_thread::sleep_for(100ms);
            }
            auto end = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= *time) {
                break;
            }
        }
    }
};

int main() {
    set_t array;

    const std::chrono::seconds time = 30s;
    const int MAX_X{100};
    const int MAX_Y{100};

    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 50; ++i)
        array.insert(Factory::CreateNPC(NpcType(std::rand() % 3 + 1),
            std::rand() % MAX_X,
            std::rand() % MAX_Y));

    std::cout << "Starting list:" << std::endl << array;

    std::thread fight_thread(std::ref(FightManager::get()), (void*) &time);

    std::thread move_thread([&array, MAX_X, MAX_Y, time]() {
        auto start = std::chrono::steady_clock::now();
        while (true) {
            for (std::shared_ptr<NPC> npc : array) {
                if (npc->is_alive()) {
                    int shift_x = std::rand() % (npc->get_move_distance() * 2) - npc->get_move_distance();
                    int shift_y = std::rand() % (npc->get_move_distance() * 2) - npc->get_move_distance();
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }
            // lets fight
            for (std::shared_ptr<NPC> npc : array)
                for (std::shared_ptr<NPC> other : array)
                    if (other != npc && npc->is_alive() && other->is_alive() && npc->is_close(other)) {
                        FightManager::get().add_event({npc, other});
                    }
            std::this_thread::sleep_for(50ms);
            auto end = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= time) {
                break;
            }
        }
        });

    auto start = std::chrono::steady_clock::now();
    while (true) {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        std::array<std::array<char, grid>, grid> fields{std::array<char, grid>{0}};
        for (std::shared_ptr<NPC> npc : array) {
            auto [x, y] = npc->position();
            int i = x / step_x;
            int j = y / step_y;
            if (i >= grid) i = grid - 1;
            if (j >= grid) j = grid - 1;

            if (npc->is_alive()) {
                switch (npc->get_type()) {
                    case SquirrelType:
                        fields[i][j] = 'S';
                        break;
                    
                    case SlaveTraderType:
                        fields[i][j] = 'W';
                        break;
                    
                    case KnightType:
                        fields[i][j] = 'D';
                        break;

                    default:
                        break;
                }
            }
        }
        {
            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j) {
                for (int i = 0; i < grid; ++i) {
                    char c = fields[i][j];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
        auto end = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= time) {
            break;
        }
    }

    move_thread.join();
    fight_thread.join();

    std::cout << "Survivors: " << std::endl << array;

    return 0;
}
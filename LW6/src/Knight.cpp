#include "squirrel.hpp"
#include "SlaveTrader.hpp"
#include "Knight.hpp"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print() {
    std::cout << *this;
}

void Knight::save(std::ostream &os) {
    os << KnightType << std::endl;
    NPC::save(os);
}

bool Knight::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_Knight(std::dynamic_pointer_cast<Knight>(shared_from_this()));
}

bool Knight::visit_SlaveTrader(std::shared_ptr<SlaveTrader> other) {
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Knight &knight) {
    os << "Knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}
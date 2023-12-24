#include "squirrel.hpp"
#include "SlaveTrader.hpp"
#include "squirrel.hpp"

SlaveTrader::SlaveTrader(int x, int y) : NPC(SlaveTraderType, x, y) {}
SlaveTrader::SlaveTrader(std::istream &is) : NPC(SlaveTraderType, is) {}

void SlaveTrader::print() {
    std::cout << *this;
}

void SlaveTrader::save(std::ostream &os) {
    os << SlaveTraderType << std::endl;
    NPC::save(os);
}

bool SlaveTrader::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_SlaveTrader(std::dynamic_pointer_cast<SlaveTrader>(shared_from_this()));
}

bool SlaveTrader::visit_Squirrel(std::shared_ptr<Squirrel> other) {
    fight_notify(other, true);
    return true;
}
 

std::ostream &operator<<(std::ostream &os, SlaveTrader &SlaveTrader) {
    os << "SlaveTrader: " << *static_cast<NPC *>(&SlaveTrader) << std::endl;
    return os;
}
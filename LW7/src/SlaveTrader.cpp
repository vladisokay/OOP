#include "SlaveTrader.hpp"

SlaveTrader::SlaveTrader(int x, int y) : NPC(SlaveTraderType, x, y) {
    move_distance = 40;
    kill_distance = 5;
}

SlaveTrader::SlaveTrader(std::istream& is) : NPC(SlaveTraderType, is) {
    move_distance = 40;
    kill_distance = 5;
}

bool SlaveTrader::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<SlaveTrader> defender = std::dynamic_pointer_cast<SlaveTrader>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void SlaveTrader::print() {
    std::cout << *this;
}

void SlaveTrader::save(std::ostream& os) {
    os << SlaveTraderType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, SlaveTrader& slaveTrader) {
    os << "SlaveTrader " << *static_cast<NPC*>(&slaveTrader) << std::endl;
    return os;
}
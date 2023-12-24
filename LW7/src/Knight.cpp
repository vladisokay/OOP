#include "Knight.hpp"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {
    move_distance = 10;
    kill_distance = 10;
}

Knight::Knight(std::istream& is) : NPC(KnightType, is) {
    move_distance = 10;
    kill_distance = 10;
}

bool Knight::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Knight> defender = std::dynamic_pointer_cast<Knight>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Knight::print() {
    std::cout << *this;
}

void Knight::save(std::ostream& os) {
    os << KnightType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Knight& knight) {
    os << "Knight " << *static_cast<NPC*>(&knight) << std::endl;
    return os;
}
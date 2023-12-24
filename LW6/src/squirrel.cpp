#include "squirrel.hpp"

Squirrel::Squirrel(int x, int y) : NPC(SquirrelType, x, y) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}

void Squirrel::print() {
    std::cout << *this;
}

void Squirrel::save(std::ostream &os) {
    os << SquirrelType << std::endl;
    NPC::save(os);
}

bool Squirrel::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_Squirrel(std::dynamic_pointer_cast<Squirrel>(shared_from_this()));
}

bool Squirrel::visit_Squirrel(std::shared_ptr<Squirrel> other) {
    fight_notify(other, true);
    return true;
}


std::ostream &operator<<(std::ostream &os, Squirrel &squirrel) {
    os << "squirrel: " << *static_cast<NPC *>(&squirrel) << std::endl;
    return os;
}
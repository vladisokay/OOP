#ifndef SQUIRREL_HPP
#define SQUIRREL_HPP

#include "npc.hpp"

struct Squirrel final : public NPC {
    Squirrel(int x, int y);
    Squirrel(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    
    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_Squirrel(std::shared_ptr<Squirrel> other) override;
    
    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);
};

#endif
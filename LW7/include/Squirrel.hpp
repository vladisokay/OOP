#ifndef SQUIRREL_HPP
#define SQUIRREL_HPP

#include "npc.hpp"
#include "visitors.hpp"

class Squirrel final : public NPC {
public:
    Squirrel(int x, int y);
    Squirrel(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Squirrel& squirrel);
};

#endif
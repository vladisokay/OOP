#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "npc.hpp"
#include "visitors.hpp"

class Knight final : public NPC {
public:
    Knight(int x, int y);
    Knight(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Knight& knight);
};

#endif
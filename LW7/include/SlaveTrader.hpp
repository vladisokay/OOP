#ifndef SLAVETRADER_HPP
#define SLAVETRADER_HPP

#include "npc.hpp"
#include "visitors.hpp"

class SlaveTrader final : public NPC {
public:

    SlaveTrader(int x, int y);
    SlaveTrader(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, SlaveTrader& slaveTrader);
};

#endif
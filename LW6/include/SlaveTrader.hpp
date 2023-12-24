#ifndef SLAVETRADER_HPP
#define SLAVETRADER_HPP

struct SlaveTrader final : public NPC {
    SlaveTrader(int x, int y);
    SlaveTrader(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_Squirrel(std::shared_ptr<Squirrel> other) override;
    

    friend std::ostream &operator<<(std::ostream &os, SlaveTrader &SlaveTrader);
};

#endif
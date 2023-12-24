#ifndef KNIGHT_HPP
#define KNIGHT_HPP

struct Knight final : public NPC {
    Knight(int x, int y);
    Knight(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_SlaveTrader(std::shared_ptr<SlaveTrader> other) override;

    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};

#endif
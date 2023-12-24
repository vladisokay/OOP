#ifndef NPC_HPP
#define NPC_HPP

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>


// type for npcs
struct NPC;
struct Squirrel;
struct Knight;
struct SlaveTrader;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    SquirrelType = 1,
    KnightType = 2,
    SlaveTraderType = 3
};

struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC> {
    NpcType type;
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;


    virtual bool visit_Squirrel(std::shared_ptr<Squirrel> other);
    virtual bool visit_Knight(std::shared_ptr<Knight> other);
    virtual bool visit_SlaveTrader(std::shared_ptr<SlaveTrader> other);

    virtual bool accept(std::shared_ptr<NPC> attacker) = 0;

    virtual void print() = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};

#endif
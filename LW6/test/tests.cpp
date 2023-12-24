#include <gtest/gtest.h>
#include "../src/npc.cpp"
#include "../src/squirrel.cpp"
#include "../src/SlaveTrader.cpp"
#include "../src/Knight.cpp"

TEST(FightTest, SquirrelAttackSquirrel) {
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(0, 0);
    std::shared_ptr<NPC> squirrelTwo = std::make_shared<Squirrel>(1, 1);
    bool success = squirrelTwo->accept(squirrel);
    ASSERT_TRUE(success);
}

TEST(FightTest, KnightAttackSlaveTrader) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0);
    std::shared_ptr<NPC> slaveTrader = std::make_shared<SlaveTrader>(1, 1);
    bool success = slaveTrader->accept(knight);
    ASSERT_TRUE(success);
}

TEST(FightTest, SlaveTraderAttackSquirrel) {
    std::shared_ptr<NPC> slaveTrader = std::make_shared<SlaveTrader>(1, 1);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(2, 2);
    bool success = squirrel->accept(slaveTrader);
    ASSERT_TRUE(success);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
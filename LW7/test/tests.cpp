#include <gtest/gtest.h>
#include "../src/npc.cpp"
#include "../src/Knight.cpp"
#include "../src/SlaveTrader.cpp"
#include "../src/Squirrel.cpp"
#include "../include/visitors.hpp"

std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(21, 17);
std::shared_ptr<NPC> slaveTrader = std::make_shared<SlaveTrader>(20, 16);
std::shared_ptr<NPC> knight = std::make_shared<Knight>(100, 17);
std::shared_ptr<Visitor> squirrel_visitor = std::make_shared<SquirrelVisitor>();
std::shared_ptr<Visitor> SlaveTrader_visitor = std::make_shared<SlaveTraderVisitor>();
std::shared_ptr<Visitor> Knight_visitor = std::make_shared<KnightVisitor>();

TEST(VisitorTest, Squirrel) {
    ASSERT_TRUE(squirrel_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_FALSE(squirrel_visitor->visit(std::static_pointer_cast<SlaveTrader>(slaveTrader)));
    ASSERT_FALSE(squirrel_visitor->visit(std::static_pointer_cast<Knight>(knight)));
}

TEST(VisitorTest, SlaveTrader) {
    ASSERT_TRUE(SlaveTrader_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_FALSE(SlaveTrader_visitor->visit(std::static_pointer_cast<SlaveTrader>(slaveTrader)));
    ASSERT_FALSE(SlaveTrader_visitor->visit(std::static_pointer_cast<Knight>(knight)));
}

TEST(VisitorTest, Knight) {
    ASSERT_FALSE(Knight_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_TRUE(Knight_visitor->visit(std::static_pointer_cast<SlaveTrader>(slaveTrader)));
    ASSERT_FALSE(Knight_visitor->visit(std::static_pointer_cast<Knight>(knight)));
}

TEST(AcceptTest, Squirrel) {
    ASSERT_TRUE(squirrel->accept(squirrel));
    ASSERT_FALSE(slaveTrader->accept(squirrel));
    ASSERT_FALSE(knight->accept(squirrel));    
}

TEST(AcceptTest, SlaveTrader) {
    ASSERT_TRUE(squirrel->accept(slaveTrader));
    ASSERT_FALSE(slaveTrader->accept(slaveTrader));
    ASSERT_FALSE(knight->accept(slaveTrader));
}

TEST(AcceptTest, Knight) {
    ASSERT_FALSE(squirrel->accept(knight));
    ASSERT_TRUE(slaveTrader->accept(knight));
    ASSERT_FALSE(knight->accept(knight));
}

TEST(DistanceTest, IsClose) {
    ASSERT_FALSE(squirrel->is_close(knight));
    ASSERT_FALSE(knight->is_close(slaveTrader));
    ASSERT_TRUE(slaveTrader->is_close(squirrel));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
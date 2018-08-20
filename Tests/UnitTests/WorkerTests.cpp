#include <Worker.h>

#include <gtest/gtest.h>

using namespace Civilizationpp;

class WorkerTest : public ::testing::Test {
 protected:
    Worker worker{0, 0};
};
class ObtainableTileTest : public Obtainable {
 public:
    int GetFood() { return Food(); }
    int GetProduction() { return Production(); }
    int GetGold() { return Gold(); }
};

TEST_F(WorkerTest, WorkerCanMoveAnywhere) {
    auto position = worker.Move(1, 2);
    ASSERT_EQ(position.first == 1, position.second == 2);
}
TEST_F(WorkerTest, WorkerCanChangeTile) {
    ObtainableTileTest tile;
    worker.Build(&tile);
    ASSERT_EQ(tile.GetFood(), 1);
    int t = 10;
    worker.Build(&tile, [t]() -> int { return t + 10; });
    ASSERT_EQ(tile.GetFood(), 20);
}
#include <Worker.h>

#include <gtest/gtest.h>
using namespace Civilizationpp;
class WorkerTest : public ::testing::Test {
 protected:
    Worker worker{0, 0};
};
class ObtainableTileTest :public Obtainable{
 public:
    int GetFood() { 
		return Food(HexTile());
	}
    int GetProduction() { 
		return Production(HexTile());
	}
    int GetGold() {
		return Gold(HexTile());
	}
};

TEST_F(WorkerTest, WorkerCanMoveAnywhere) {
    auto position = worker.Move(1, 2);
    ASSERT_EQ(position.first == 1, position.second == 2);
}
TEST_F(WorkerTest, WorkerCanChangeTile) {
    ObtainableTileTest tile;
    worker.Build(&tile);
    ASSERT_EQ(tile.GetFood(), 1);
    worker.Build(&tile, [](HexTile tile) -> int { return 20; });
    ASSERT_EQ(tile.GetFood(), 20);
}
#include <gtest/gtest.h>

#include <Worker.h>

using namespace Civilizationpp;

TEST(Worker, CanMoveAnywhere)
{
    Worker worker{ 0, 0 };

    HexMap::GetInstance()->Generate(GameSettings(30, 30));

    worker.Move(1, 2);

    auto position = worker.GetPosition();
    ASSERT_TRUE(position.first == 1 && position.second == 2);
}

TEST(Worker, CanChangeTile)
{
    Worker worker{ 0, 0 };
    BasicResource res;

    HexMap::GetInstance()->Generate(GameSettings(30, 30));

    worker.Build(&res);

    auto position = worker.GetPosition();
    ASSERT_EQ(HexMap::GetInstance()
                  ->GetTile(position.first, position.second)
                  ->GetTerrain()
                  ->GetResource(),
              &res);
}
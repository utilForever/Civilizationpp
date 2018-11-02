#include <Resource.h>
#include <Worker.h>

#include <gtest/gtest.h>

using namespace Civilizationpp;

class WorkerTest : public ::testing::Test
{
 protected:
    void SetUp() override
    {
        HexMap::GetInstance()->Generate(GameSettings(30, 30));
    }
    Worker worker{ 0, 0 };
};

TEST_F(WorkerTest, WorkerCanMoveAnywhere)
{
    worker.Move(1, 2);
    auto position = worker.GetPosition();
    ASSERT_EQ(position.first == 1, position.second == 2);
}
TEST_F(WorkerTest, WorkerCanChangeTile)
{
    Resource res;
    worker.Build(&res);
    auto position = worker.GetPosition();
    ASSERT_EQ(HexMap::GetInstance()->GetTile(position.first, position.second)->GetTerrain()->GetResource(),
              &res);
}
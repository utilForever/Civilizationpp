#include <gtest/gtest.h>

#include <BaseUnit.h>

using namespace Civilizationpp;

TEST(BaseUnit, ShouldCanMove)
{
    BaseUnit baseunit{ 1, 2 };

    baseunit.Move(+1, -3);
    auto position = baseunit.GetPosition();
    ASSERT_TRUE(position.first == +1 && position.second == -3);

    baseunit.Move(-1, +3);
    position = baseunit.GetPosition();
    ASSERT_TRUE(position.first == -1 && position.second == +3);

	baseunit.Move(-1, +30);
    position = baseunit.GetPosition();
    ASSERT_TRUE(position.first == -1 && position.second == +30);

    baseunit.Move(-13, +30);
    position = baseunit.GetPosition();
    ASSERT_TRUE(position.first == -13 && position.second == +30);
}
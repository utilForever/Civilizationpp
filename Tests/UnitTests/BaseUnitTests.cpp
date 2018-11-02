#include <gtest/gtest.h>

#include <BaseUnit.h>

using namespace Civilizationpp;

TEST(BaseUnit, ShouldCanMove)
{
    BaseUnit baseunit{ 1, 2 };

    auto position = baseunit.Move(+1, -3);
    ASSERT_DOUBLE_EQ(position.first == +1, position.second == -3);

    position = baseunit.Move(-1, +3);
    ASSERT_DOUBLE_EQ(position.first == -1, position.second == +3);

    position = baseunit.Move(-1, +30);
    ASSERT_DOUBLE_EQ(position.first == -1, position.second == +30);

    position = baseunit.Move(-13, +30);
    ASSERT_DOUBLE_EQ(position.first == -13, position.second == +30);
}
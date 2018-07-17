#include <BaseUnit.h>

#include <gtest/gtest.h>
using namespace Civilizationpp;
class BaseUnitTest : public ::testing::Test {
 protected:
    BaseUnit baseunit{1,2};
};
TEST_F(BaseUnitTest, BaseUnitShuldCanMove) {
    auto position = baseunit.Move(+1, -3);
    ASSERT_DOUBLE_EQ(position.first == +1, position.second == -3);
    position = baseunit.Move(-1, +3);
    ASSERT_DOUBLE_EQ(position.first == -1, position.second == +3);
    position = baseunit.Move(-1, +30);
    ASSERT_DOUBLE_EQ(position.first == -1, position.second == +30);
    position = baseunit.Move(-13, +30);
    ASSERT_DOUBLE_EQ(position.first == -13, position.second == +30);
}
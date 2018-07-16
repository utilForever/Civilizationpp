#include <BaseUnit.h>

#include <gtest/gtest.h>
using namespace Civilizationpp;
class BaseUnitTest : public ::testing::Test {
 protected:
    BaseUnit baseunit{};
};
TEST_F(BaseUnitTest, BaseUnitShuldCanMove) {
    auto position = baseunit.Move(+1, -3);
    ASSERT_DOUBLE_EQ(position.first == +1, position.second == -3);
}
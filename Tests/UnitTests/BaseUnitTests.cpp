#include <BaseUnit.h>

#include <gtest/gtest.h>
using namespace Civilizationpp;
class BaseUnitTest : public ::testing::Test {
 protected:
    BaseUnit baseunit{};
};
TEST_F(BaseUnitTest, BaseUnitShuldCanMove) {
    auto[x, y] = baseunit.Move(+1, +3);
    ASSERT_DOUBLE_EQ(x == +1, y == +3);

}
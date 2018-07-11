#include <BaseUnit.h>

#include <gtest/gtest.h>
using namespace Civilizationpp;
class BaseUnitTest : public ::testing::Test {
 protected:
    BaseUnit baseunit{};
};
TEST_F(BaseUnitTest, BaseUnitShuldCanMove) { ASSERT_FALSE(false); }
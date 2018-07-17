#include <UnitFactory.h>

#include <gtest/gtest.h>
using namespace Civilizationpp;
class UnitFactoryTest : public ::testing::Test {
 protected:
    UnitFactory factory{1, 1};
};
TEST_F(UnitFactoryTest, UnitCodeMustDiff) {
    ASSERT_NE(Unit::Setter, Unit::Worker);
    ASSERT_EQ(Unit::Codes::Setter, 0);
    ASSERT_EQ(Unit::Codes::Worker, 1);
}
TEST_F(UnitFactoryTest, UnitFactoryCanCreatUnit) {
    Setter setter = factory.CreatUnit<Setter>(Unit::Codes::Setter);
}
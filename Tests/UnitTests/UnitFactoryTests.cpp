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
    Setter* setter = dynamic_cast<Setter*>(factory.CreatUnit(Unit::Setter));
    ASSERT_NE(setter, nullptr);
    delete (setter);
    setter = dynamic_cast<Setter*>(factory.CreatUnit(Unit::Worker));
    ASSERT_EQ(setter, nullptr);
    delete (setter);
    Worker* worker = dynamic_cast<Worker*>(factory.CreatUnit(Unit::Worker));
    ASSERT_NE(worker, nullptr);
    delete (worker);
    worker = dynamic_cast<Worker*>(factory.CreatUnit(Unit::Setter));
    ASSERT_EQ(worker, nullptr);
    delete (worker);
}
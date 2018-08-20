#include <UnitFactory.h>

#include <gtest/gtest.h>

using namespace Civilizationpp;
class UnitFactoryTest : public ::testing::Test {
 protected:
    UnitFactory factory{1, 1};
};

TEST_F(UnitFactoryTest, UnitFactoryCanCreatUnit) {
    Setter* setter = dynamic_cast<Setter*>(factory.CreatUnit(Unit::Codes::Setter));
    ASSERT_NE(setter, static_cast<Setter*>(nullptr));
    delete (setter);
    
    setter = dynamic_cast<Setter*>(factory.CreatUnit(Unit::Codes::Worker));
    ASSERT_EQ(setter, static_cast<Setter*>(nullptr));
    delete (setter);

    Worker* worker = dynamic_cast<Worker*>(factory.CreatUnit(Unit::Codes::Worker));
    ASSERT_NE(worker, static_cast<Worker*>(nullptr));
    delete (worker);

    worker = dynamic_cast<Worker*>(factory.CreatUnit(Unit::Codes::Setter));
    ASSERT_EQ(worker, static_cast<Worker*>(nullptr));
    delete (worker);
   
}
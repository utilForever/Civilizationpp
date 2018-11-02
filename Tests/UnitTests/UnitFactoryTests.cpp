#include <gtest/gtest.h>

#include <UnitFactory.h>

using namespace Civilizationpp;

TEST(UnitFactory, CanCreatUnit)
{
    UnitFactory factory{ 1, 1 };

    Setter* setter =
        dynamic_cast<Setter*>(factory.CreatUnit(Unit::Codes::Setter));
    ASSERT_NE(setter, static_cast<Setter*>(nullptr));
    delete (setter);

    setter = dynamic_cast<Setter*>(factory.CreatUnit(Unit::Codes::Worker));
    ASSERT_EQ(setter, static_cast<Setter*>(nullptr));
    delete (setter);

    Worker* worker =
        dynamic_cast<Worker*>(factory.CreatUnit(Unit::Codes::Worker));
    ASSERT_NE(worker, static_cast<Worker*>(nullptr));
    delete (worker);

    worker = dynamic_cast<Worker*>(factory.CreatUnit(Unit::Codes::Setter));
    ASSERT_EQ(worker, static_cast<Worker*>(nullptr));
    delete (worker);
}
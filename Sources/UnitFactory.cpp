#include <UnitFactory.h>

using namespace Civilizationpp;

UnitFactory::UnitFactory(int x, int y)
{
    m_x = x;
    m_y = y;
}

BaseUnit* UnitFactory::CreateUnit(UnitCodes unitCode)
{
    BaseUnit* unit;

    if (unitCode == UnitCodes::Setter)
    {
        unit = new Setter(m_x, m_y);
        return unit;
    }
    else if (unitCode == UnitCodes::Worker)
    {
        unit = new Worker(m_x, m_y);
        return unit;
    }

    return nullptr;
};
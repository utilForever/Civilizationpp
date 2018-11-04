#ifndef CIVILIZATIONPP_UNIT_FACTORY_H
#define CIVILIZATIONPP_UNIT_FACTORY_H

#include <BaseUnit.h>
#include <Setter.h>
#include <Worker.h>

namespace Civilizationpp
{
enum class UnitCodes
{
    Setter = 0,
    Worker = 1
};

class UnitFactory
{
 public:
    UnitFactory(int x, int y);

    BaseUnit* CreateUnit(UnitCodes unitCode);

 private:
    int m_x;
    int m_y;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_UNIT_FACTORY_H
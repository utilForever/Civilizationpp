#ifndef CIVILIZATIONPP_UNIT_FACTORY
#define CIVILIZATIONPP_UNIT_FACTORY

#include <BaseUnit.h>
#include <Setter.h>
#include <Worker.h>

namespace Civilizationpp
{
namespace Unit
{
enum class Codes
{
    Setter = 0,
    Worker = 1
};
}

class UnitFactory
{
 private:
    int m_x;
    int m_y;

 public:
    UnitFactory(int x, int y);
    BaseUnit* CreatUnit(Unit::Codes unitCode);
};
}  // namespace Civilizationpp
#endif  // CIVILIZATIONPP_UNIT_FACTORY
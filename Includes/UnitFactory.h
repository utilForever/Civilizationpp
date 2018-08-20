#ifndef CIVILIZATIONPP_UNIT_FACTORY
#define CIVILIZATIONPP_UNIT_FACTORY

#include <BaseUnit.h>
#include <Setter.h>
#include <Worker.h>

namespace Civilizationpp {
namespace Unit {
enum class Codes { Setter = 0, Worker = 1 };
}

class UnitFactory {
 private:
    int m_x;
    int m_y;

 public:
    UnitFactory(int x, int y);
    auto CreatUnit(Unit::Codes unitCode) -> BaseUnit* {
        BaseUnit* unit;
        if (unitCode == Unit::Codes::Setter) {
            unit = new Setter(m_x, m_y);
            return unit;
        } else if (unitCode == Unit::Codes::Worker) {
            unit = new Worker(m_x, m_y);
            return unit;
        }
        return nullptr;
    };
};
}  // namespace Civilizationpp
#endif  // CIVILIZATIONPP_UNIT_FACTORY
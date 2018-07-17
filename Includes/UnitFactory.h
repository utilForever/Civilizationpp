#pragma once
#include <BaseUnit.h>
#include <Setter.h>
#include <Worker.h>
namespace Civilizationpp {
namespace Unit {
enum Codes { Setter = 0, Worker = 1 };
}
class UnitFactory {
 private:
    int m_x;
    int m_y;

 public:
    UnitFactory(int x, int y);
    auto CreatUnit(Unit::Codes unitCode) -> BaseUnit* {
        BaseUnit* unit;
        if (unitCode == Unit::Setter) {
            unit = new Setter(m_x, m_y);
            return unit;
        }
        if (unitCode == Unit::Worker) {
            unit = new Worker(m_x, m_y);
            return unit;
		}
        return nullptr;
    };
};
}  // namespace Civilizationpp
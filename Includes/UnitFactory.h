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
    template <typename T>
    auto CreatUnit(Unit::Codes unitCode) -> T& {
        if (unitCode == Unit::Setter) {
            return Setter(m_x, m_y);
        }
        else if (unitCode == Unit::Worker) {
            return Worker(m_x, m_y);
        }
        return nullptr;
    };
};
}  // namespace Civilizationpp
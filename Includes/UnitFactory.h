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
};
}  // namespace Civilizationpp
#pragma once
#include <HexMap.h>
#include <tuple>
namespace Civilizationpp {
class BaseUnit {
 private:
    int m_positionX{0};
    int m_positionY{0};

 public:
    BaseUnit(int x, int y);
    virtual std::pair<int, int> Move(int x, int y) noexcept;
};
}  // namespace Civilizationpp
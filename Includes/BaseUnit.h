#ifndef CIVILIZATIONPP_BASE_UNIT_H
#define CIVILIZATIONPP_BASE_UNIT_H

#include <HexMap.h>

#include <tuple>

namespace Civilizationpp
{
enum class DirectionVector
{
    Idle,
    Up,
    Down,
    Left,
    Right,
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight
};
class BaseUnit
{
 private:
    int m_positionX{ 0 };
    int m_positionY{ 0 };
    int m_movement{ 0 };

    DirectionVector GetDirection(int destinationX, int destinationY);

 public:
    BaseUnit(int x, int y);
    virtual ~BaseUnit() = default;

    virtual void Move(int x, int y) noexcept;
    std::pair<int, int> GetPosition() const;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_BASE_UNIT_H
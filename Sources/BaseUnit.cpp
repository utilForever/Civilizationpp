#include <BaseUnit.h>

using namespace Civilizationpp;

BaseUnit::BaseUnit(HexMap* map, int x, int y) {
    m_positionX = x;
    m_positionY = y;
    m_map = map;
}
std::pair<int, int> BaseUnit::Move(int x, int y) noexcept {
    m_positionX = x;
    m_positionY = y;
    return {m_positionX, m_positionY};
}

std::pair<int, int> Civilizationpp::BaseUnit::GetPosition() {
    return {m_positionX,m_positionY};
}

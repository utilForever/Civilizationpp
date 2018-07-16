#include <BaseUnit.h>
namespace Civilizationpp {
std::pair<int,int> BaseUnit::Move(int x, int y) {
    m_positionX = x;
    m_positionY = y;
	return { m_positionX, m_positionY };
}
}  // namespace Civilizationpp
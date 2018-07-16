#include <BaseUnit.h>
namespace Civilizationpp {
BaseUnit::BaseUnit(){}
BaseUnit::BaseUnit(int x, int y){ 
	m_positionX = x;
    m_positionY = y;
} 
std::pair<int,int> BaseUnit::Move(int x, int y) {
    m_positionX = x;
    m_positionY = y;
	return { m_positionX, m_positionY };
}
}  // namespace Civilizationpp
#include <BaseUnit.h>
using namespace Civilizationpp;
BaseUnit::BaseUnit(int x, int y) { 
	m_positionX = x;
    m_positionY = y;
} 
std::pair<int,int> BaseUnit::Move(int x, int y) noexcept{
    m_positionX = x;
    m_positionY = y;
	return { m_positionX, m_positionY };
}
#include <BaseUnit.h>

using namespace Civilizationpp;

BaseUnit::BaseUnit(int x, int y)
{
    m_positionX = x;
    m_positionY = y;
}

void BaseUnit::Move(int x, int y) noexcept
{
    const int deffresceX = m_positionX - x;
    const int deffresceY = m_positionY - y;

    if (m_movement < abs(deffresceX))
    {
        if (deffresceX > 0)
        {
            m_positionX += m_movement;
        }
        else
        {
            m_positionX -= m_movement;
        }
    }
    else
    {
        m_positionX = x;
    }

    if (m_movement < abs(deffresceY))
    {
        if (deffresceY > 0)
        {
            m_positionY += m_movement;
        }
        else
        {
            m_positionY -= m_movement;
        }
    }
    else
    {
        m_positionY = y;
    }
}

std::pair<int, int> BaseUnit::GetPosition() const
{
    return { m_positionX, m_positionY };
}

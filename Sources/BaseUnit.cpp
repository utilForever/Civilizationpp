#include <BaseUnit.h>

using namespace Civilizationpp;

BaseUnit::BaseUnit(int x, int y)
{
    m_positionX = x;
    m_positionY = y;
}

void BaseUnit::Move(int x, int y) noexcept
{
    while (true)
    {
        DirectionVector vector = GetDirection(x, y);
        if (vector == DirectionVector::Idle)
        {
            // Do Nothing
            break;
        }
        else if (vector == DirectionVector::Up)
        {
            if (m_positionY % 2 == 0)
            {
                m_positionX += 1;
            }
            m_positionY += 1;
        }
        else if (vector == DirectionVector::Down)
        {
            if (m_positionY % 2 == 0)
            {
                m_positionX -= 1;
            }
            m_positionY -= 1;
        }
        else if (vector == DirectionVector::Left)
        {
            m_positionX -= 1;
        }
        else if (vector == DirectionVector::Right)
        {
            m_positionX += 1;
        }
        else if (vector == DirectionVector::TopLeft)
        {
            m_positionX += 1;
            m_positionY -= 1;
        }
        else if (vector == DirectionVector::TopRight)
        {
            m_positionY -= 1;
        }
        else if (vector == DirectionVector::BottomLeft)
        {
            m_positionX -= 1;
            m_positionY += 1;
        }
        else if (vector == DirectionVector::BottomRight)
        {
            m_positionY += 1;
        }
    }
}

std::pair<int, int> BaseUnit::GetPosition() const
{
    return { m_positionX, m_positionY };
}

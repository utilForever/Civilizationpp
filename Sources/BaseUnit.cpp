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
        else
        {
            m_movement -= HexMap::GetInstance()
                              ->GetTile(x, y)
                              ->GetTerrain()
                              ->GetMovement();
        }

        if (vector == DirectionVector::Up)
        {
            if (m_positionY % 2 == 0)
            {
                MoveTopLeft();
            }
            MoveTopRight();
        }
        else if (vector == DirectionVector::Down)
        {
            if (m_positionY % 2 == 0)
            {
                MoveBottomLeft();
            }
            MoveBottomRight();
        }
        else if (vector == DirectionVector::Left)
        {
            MoveLeft();
        }
        else if (vector == DirectionVector::Right)
        {
            MoveRight();
        }
        else if (vector == DirectionVector::TopLeft)
        {
            MoveTopLeft();
        }
        else if (vector == DirectionVector::TopRight)
        {
            MoveTopRight();
        }
        else if (vector == DirectionVector::BottomLeft)
        {
            MoveBottomLeft();
        }
        else if (vector == DirectionVector::BottomRight)
        {
            MoveBottomRight();
        }
    }
}

void BaseUnit::MoveLeft()
{
    m_positionX -= 1;
}
void BaseUnit::MoveRight()
{
    m_positionX += 1;
}
void BaseUnit::MoveTopLeft()
{
    m_positionY -= 1;
}
void BaseUnit::MoveTopRight()
{
    m_positionX += 1;
    m_positionY -= 1;
}
void BaseUnit::MoveBottomLeft()
{
    m_positionX -= 1;
    m_positionY += 1;
}
void BaseUnit::MoveTopRight()
{
    m_positionY += 1;
}

std::pair<int, int> BaseUnit::GetPosition() const
{
    return { m_positionX, m_positionY };
}

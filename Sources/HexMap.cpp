#include "HexMap.h"
#include "HexTile.h"
#include <utility>
#include <vector>

using namespace Civilizationpp;

HexMap::HexMap(GameSettings settings) : m_settings(settings)
{
    m_map = new Hex*[settings.rowCount];
    for (int row = 0; row < settings.rowCount; ++row)
    {
        m_map[row] = new Hex[settings.rowCount]{};
    }
}

HexMap::HexMap(const HexMap& other) : m_settings(other.m_settings)
{
    for (int row = 0; row < m_settings.rowCount; ++row)
    {
        for (int col = 0; col < m_settings.colCount; ++col)
        {
           m_map[row][col] = other.m_map[row][col];
        }
    }
}

HexMap::HexMap(HexMap&& other) noexcept :
    m_settings(other.m_settings),
    m_map(other.m_map)
{
    other.m_map = nullptr;
}

HexMap::~HexMap()
{
    for (int row = 0; row < m_settings.rowCount; ++row)
    {
        delete[] m_map[row];
    }
    delete[] m_map;
}

HexMap& HexMap::operator=(const HexMap& other)
{
    if (this == &other)
    {
        return *this;
    }

    HexMap temp{other};
    *this = std::move(temp);
    return *this;
}

HexMap& HexMap::operator=(HexMap&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }

    for (int row = 0; row < m_settings.rowCount; ++row)
    {
        delete[] m_map[row];
    }
    delete[] m_map;

    m_map = other.m_map;
    other.m_map = nullptr;

    m_settings = other.m_settings;

    return *this;
}

Hex* HexMap::GetTile(int r, int q) const
{
    int originRow = (m_settings.rowCount - 1) / 2;
    int originCol = (m_settings.colCount - 1) / 2;

    if ((originRow + r < 0 || originRow + r >= m_settings.rowCount) ||
        (originCol + q < 0 || originCol + q >= m_settings.colCount))
    {
        return nullptr;
    }

    return &(m_map[originRow + r][originRow + q]);
}

std::vector<Hex*> HexMap::GetAdjacencies(int r, int q) const
{
    std::vector<Hex*> ret{};
    ret.push_back(GetTile(r - 1, q));
    ret.push_back(GetTile(r - 1, q + 1));
    ret.push_back(GetTile(r, q + 1));
    ret.push_back(GetTile(r + 1, q));
    ret.push_back(GetTile(r + 1, q - 1));
    ret.push_back(GetTile(r, q - 1));
    return ret;
}
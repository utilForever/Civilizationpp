#include <HexMap.h>
#include <HexTile.h>

#include <algorithm>
#include <utility>
#include <vector>

using namespace Civilizationpp;

HexMap::HexMap(GameSettings settings) :
    m_settings(settings),
    m_map(settings.rowCount * settings.colCount)
{
}

HexMap::HexMap(const HexMap& other) :
    m_settings(other.m_settings),
    m_map(other.m_map)
{
}

HexMap::HexMap(HexMap&& other) noexcept :
    m_settings(other.m_settings),
    m_map(std::move(other.m_map))
{
}

HexMap::~HexMap()
{
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

    m_map = std::move(other.m_map);
    m_settings = other.m_settings;

    return *this;
}

HexTile* HexMap::GetTile(int r, int q) const
{
    const int rowCount = static_cast<int>(m_settings.rowCount);
    const int colCount = static_cast<int>(m_settings.colCount);

    // Convert axial coordinates into 2d array index
    int originRow = (rowCount - 1) / 2;
    int originCol = (colCount - 1) / 2;

    int tileRow = originRow + r;
    if (originRow + r < 0 || originRow + r >= rowCount)
    {
        return nullptr;
    }

    int tileCol = (originCol + q) % colCount;
    if (tileCol < 0)
    {
        tileCol += colCount;
    }

    // Convert 2d array index into 1d array index
    int index = tileCol + tileRow * colCount;
    return const_cast<HexTile *>(&(m_map[index]));
}

std::vector<HexTile*> HexMap::GetAdjacencies(int r, int q) const
{
    std::vector<HexTile*> ret{};
    ret.push_back(GetTile(r - 1, q));
    ret.push_back(GetTile(r - 1, q + 1));
    ret.push_back(GetTile(r, q + 1));
    ret.push_back(GetTile(r + 1, q));
    ret.push_back(GetTile(r + 1, q - 1));
    ret.push_back(GetTile(r, q - 1));
    ret.erase(std::remove(ret.begin(), ret.end(), nullptr), ret.end());
    return ret;
}
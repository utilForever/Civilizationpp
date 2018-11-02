#include <HexMap.h>
#include <HexTile.h>

#include <algorithm>
#include <utility>
#include <vector>

using namespace Civilizationpp;

HexMap* HexMap::m_instance = nullptr;

HexMap* HexMap::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new HexMap();
    }

    return m_instance;
}

void HexMap::Generate(GameSettings settings)
{
    m_settings = settings;
    m_map.resize(settings.rowCount * settings.colCount);
}

HexMap::HexMap() : m_settings(0, 0)
{
    // Do nothing
}

HexMap::~HexMap()
{
    delete m_instance;
}

const HexTile* HexMap::GetTile(int r, int q) const
{
    const int rowCount = static_cast<int>(m_settings.rowCount);
    const int colCount = static_cast<int>(m_settings.colCount);

    // Convert axial coordinates into 2d array index
    int originRow = (rowCount - 1) / 2;
    int originCol = (colCount - 1) / 2;

    int tileRow = originRow + r;
    if (tileRow < 0 || tileRow >= rowCount)
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

    return &m_map[index];
}

std::vector<const HexTile*> HexMap::GetAdjacencies(int r, int q) const
{
    std::vector<const HexTile*> ret{};

    ret.push_back(GetTile(r - 1, q));
    ret.push_back(GetTile(r - 1, q + 1));
    ret.push_back(GetTile(r, q + 1));
    ret.push_back(GetTile(r + 1, q));
    ret.push_back(GetTile(r + 1, q - 1));
    ret.push_back(GetTile(r, q - 1));
    ret.erase(std::remove(ret.begin(), ret.end(), nullptr), ret.end());

    return ret;
}
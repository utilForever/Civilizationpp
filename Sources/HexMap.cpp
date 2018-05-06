#include "HexMap.h"
#include "HexTile.h"
#include <utility>

HexMap::HexMap()
{
    mMap = new Hex*[3];
    for (int row = 0; row < 3; ++row)
    {
        mMap[row] = new Hex[3]{};
    }
}

HexMap::HexMap(const HexMap& other) : HexMap()
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
           mMap[row][col] = other.mMap[row][col];
        }
    }
}

HexMap::HexMap(HexMap&& other) noexcept : mMap(other.mMap)
{
    other.mMap = nullptr;
}

HexMap::~HexMap()
{
    for (int row = 0; row < 3; ++row)
    {
        delete[] mMap[row];
    }
    delete[] mMap;
}

HexMap& HexMap::operator=(const HexMap& other)
{
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

    for (int row = 0; row < 3; ++row)
    {
        delete[] mMap[row];
    }
    delete[] mMap;

    mMap = other.mMap;
    other.mMap = nullptr;
    return *this;
}


Hex* HexMap::get(int row, int column) const
{
    if ((row < -1 || row > 1) ||
        (column < -1 || column > 1))
    {
        return nullptr;
    }

    //(0,0) corresponds to the center of the 2-d array.
    return &(mMap[row + 1][column + 1]);
}

#include "HexMap.h"
#include "HexTile.h"
#include <utility>

HexMap::HexMap()
{
    mMap = new Hex*[mNumOfRows];
    for (int row = 0; row < mNumOfColumns; ++row)
    {
        mMap[row] = new Hex[mNumOfRows]{};
    }
}

HexMap::HexMap(const HexMap& other) : HexMap()
{
    for (int row = 0; row < mNumOfRows; ++row)
    {
        for (int col = 0; col < mNumOfColumns; ++col)
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
    for (int row = 0; row < mNumOfRows; ++row)
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

    for (int row = 0; row < mNumOfRows; ++row)
    {
        delete[] mMap[row];
    }
    delete[] mMap;

    mMap = other.mMap;
    other.mMap = nullptr;
    return *this;
}

Hex* HexMap::get(int r, int q) const
{
    int originRow = (mNumOfRows - 1) / 2;
    int originCol = (mNumOfColumns - 1) / 2;

    if ((originRow + r < 0 || originRow + r >= mNumOfRows) ||
        (originCol + q < 0 || originCol + q >= mNumOfRows))
    {
        return nullptr;
    }

    return &(mMap[originRow + r][originRow + q]);
}

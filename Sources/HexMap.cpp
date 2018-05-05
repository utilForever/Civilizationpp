#include "HexMap.h"
#include "HexTile.h"

HexMap::HexMap()
{
    mMap = new Hex*[3];
    for (int row = 0; row < 3; ++row)
    {
        mMap[row] = new Hex[3]{};
    }
}

HexMap::~HexMap()
{
    for (int row = 0; row < 3; ++row)
    {
        delete[] mMap[row];
    }
    delete[] mMap;
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

#include "HexMap.h"
#include "HexTile.h"

Hex* HexMap::get(int row, int column) const
{
    if (row == -100 || column == -100)
    {
        return nullptr;
    }
    return new Hex();
}

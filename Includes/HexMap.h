#ifndef HEX_MAP_H
#define HEX_MAP_H

#include "HexTile.h"

class HexMap
{
public:
    Hex* get(int row, int column) const;
};

#endif //HEX_MAP_H
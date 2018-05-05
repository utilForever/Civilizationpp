#ifndef HEX_MAP_H
#define HEX_MAP_H

#include "HexTile.h"

class HexMap
{
public:
    HexMap();
    ~HexMap();

    Hex* get(int row, int column) const;

private:
    // Since map won't be changed after its creation (individual
    // tiles may change, but the property of map like size won't
    // change) it would be better to use static-sized array,
    // rather than using map or unordered_map.
    Hex** mMap;
};

#endif //HEX_MAP_H
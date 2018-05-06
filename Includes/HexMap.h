#ifndef HEX_MAP_H
#define HEX_MAP_H

#include "HexTile.h"

class HexMap
{
public:
    HexMap();
    HexMap(const HexMap& other);
    HexMap(HexMap&& other) noexcept;
    ~HexMap() noexcept;

    HexMap& operator= (const HexMap& other);
    HexMap& operator= (HexMap&& other) noexcept;

    Hex* get(int row, int column) const;

private:
    // Since map won't be changed after its creation (individual
    // tiles may change, but the property of map like size won't
    // change) it would be better to use static-sized array,
    // rather than using map or unordered_map.

    // (0,0) is at the center of 2-d array. If the number of rows
    // or that of columns is even, (0, 0) is located at lefter
    // position.
    Hex** mMap;

    // Used const value to create test map, since the map generating
    // code will be handled as a sperate feature in the future.
    const int mNumOfRows = 3;
    const int mNumOfColumns = 3;
};

#endif //HEX_MAP_H
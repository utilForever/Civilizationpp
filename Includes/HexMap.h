#ifndef HEX_MAP_H
#define HEX_MAP_H

#include "HexTile.h"
#include "GameSettings.h"
#include <vector>

namespace Civilizationpp
{
    class HexMap
    {
    public:
        HexMap(GameSettings settings);
        HexMap(const HexMap& other);
        HexMap(HexMap&& other) noexcept;
        ~HexMap() noexcept;

        HexMap& operator= (const HexMap& other);
        HexMap& operator= (HexMap&& other) noexcept;

        Hex* GetTile(int r, int q) const;

        std::vector<Hex*> GetAdjacencies(int r, int q) const;

    private:
        // Since map won't be changed after its creation (individual
        // tiles may change, but the property of map like size won't
        // change) it would be better to use static-sized array,
        // rather than using map or unordered_map. (Assumed that map
        // is always in shape of rhombus.)

        // (0,0) is at the center of 2-d array. If the number of rows
        // or that of columns is even, (0, 0) is located at lefter
        // position.
        Hex** m_map;
        GameSettings m_settings;
    };
}

#endif //HEX_MAP_H
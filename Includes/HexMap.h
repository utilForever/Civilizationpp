#ifndef CIVILIZATIONPP_HEX_MAP_H
#define CIVILIZATIONPP_HEX_MAP_H

#include <GameSettings.h>
#include <HexTile.h>

#include <vector>

namespace Civilizationpp
{
class HexMap
{
 public:
    HexMap(const HexMap&) = delete;
    HexMap& operator=(const HexMap&) = delete;

    static HexMap* GetInstance();

    void Generate(GameSettings settings);

    const HexTile* GetTile(int r, int q) const;
    std::vector<const HexTile*> GetAdjacencies(int r, int q) const;

 private:
    HexMap();
    ~HexMap();

    static HexMap* m_instance;

    // Since map won't be changed after its creation (individual
    // tiles may change, but the property of map like size won't
    // change) it would be better to use static-sized array,
    // rather than using map or unordered_map. (Assumed that map
    // is always in shape of rhombus.)

    // (0,0) is at the center of 2-d array. If the number of rows
    // or that of columns is even, (0, 0) is located at lefter
    // position.
    std::vector<HexTile> m_map;
    GameSettings m_settings;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_MAP_H
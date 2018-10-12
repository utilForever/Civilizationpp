#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>

namespace Civilizationpp {
class HexTile {
 private:
    Terrain* m_Terrain;

 public:
    Terrain* GetTerrain() { return m_Terrain; }
    void ChangeTerrain(Terrain* terrain) { m_Terrain = terrain; }
    void ChangeResource(Resource* resource) {
        m_Terrain->ChangeResource(resource);
    }
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H
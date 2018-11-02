#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>

namespace Civilizationpp
{
class HexTile
{
 public:
    HexTile();

    Terrain* GetTerrain() const;
    void SetTerrain(Terrain* terrain);
    void ChangeResource(Resource* resource);

 private:
    Terrain* m_pTerrain;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H

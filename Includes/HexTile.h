#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>
#include <BasicResource.h>

namespace Civilizationpp
{
class HexTile
{
 public:
    HexTile();

    Terrain* GetTerrain() const;
    void SetTerrain(Terrain* terrain);
    void ChangeResource(BasicResource* resource) const;

 private:
    Terrain* m_pTerrain;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H

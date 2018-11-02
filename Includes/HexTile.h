#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>

namespace Civilizationpp
{
class HexTile
{
 private:
    Terrain* m_pTerrain;

 public:
    HexTile()
    {
        m_pTerrain = new Terrain();
    }
    Terrain* GetTerrain() const
    {
        return m_pTerrain;
    }
    void SetTerrain(Terrain* terrain)
    {
        m_pTerrain = terrain;
    }
    void ChangeResource(Resource* resource)
    {
        m_pTerrain->ChangeResource(resource);
    }
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H
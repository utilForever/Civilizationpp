#include <HexTile.h>
using namespace Civilizationpp;

HexTile::HexTile()
{
    m_pTerrain = new Terrain();
}

Terrain* HexTile::GetTerrain() const
{
    return m_pTerrain;
}

void HexTile::SetTerrain(Terrain* terrain)
{
    m_pTerrain = terrain;
}

void HexTile::ChangeResource(Resource* resource)
{
    m_pTerrain->ChangeResource(resource);
}
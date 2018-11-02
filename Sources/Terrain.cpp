#include <Terrain.h>
using namespace Civilizationpp;

int Terrain::GetCombat() const
{
    return m_combat;
}

::Terrain::Terrain()
    : m_category(BaseTerrain::Open), m_name(TerrainName::Plains)
{
    m_movement = 0;
    m_combat = 0;
}

int Terrain::GetMovement() const
{
    return m_movement;
}

Resource* Terrain::GetResource() const
{
    return m_pResource;
}

void Terrain::ChangeResource(Resource* resource)
{
    m_pResource = resource;
}

BaseTerrain Terrain::GetCategory() const
{
    return m_category;
}

TerrainName Terrain::GetName() const
{
    return m_name;
}
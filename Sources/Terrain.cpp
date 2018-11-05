#include <Terrain.h>

using namespace Civilizationpp;

Terrain::Terrain() : m_category(BaseTerrain::Open), m_name(TerrainName::Plains)
{
    m_movement = 0;
    m_combat = 0;
}

BaseTerrain Terrain::GetCategory() const
{
    return m_category;
}

TerrainName Terrain::GetName() const
{
    return m_name;
}

int Terrain::GetMovement() const
{
    return m_movement;
}

int Terrain::GetCombat() const
{
    return m_combat;
}

BasicResource* Terrain::GetResource() const
{
    return m_pBasicResource;
}

void Terrain::ChangeResource(BasicResource* resource)
{
    m_pBasicResource = resource;
}
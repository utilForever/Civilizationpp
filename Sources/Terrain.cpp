#include <Terrain.h>

int Civilizationpp::Terrain::GetCombat() const
{
    return m_combat;
}
Civilizationpp::Terrain::Terrain()
    : m_category(BaseTerrain::Open),
      m_name(TerrainName::Plains)
{
    m_movement = 0;
    m_combat = 0;
}
int Civilizationpp::Terrain::GetMovement() const
{
    return m_movement;
}

Civilizationpp::Resource* Civilizationpp::Terrain::GetResource() const
{
    return m_pResource;
}
void Civilizationpp::Terrain::ChangeResource(Resource* resource)
{
    m_pResource = resource;
}
Civilizationpp::BaseTerrain Civilizationpp::Terrain::GetCategory() const
{
    return m_category;
}
Civilizationpp::TerrainName Civilizationpp::Terrain::GetName() const
{
    return m_name;
}
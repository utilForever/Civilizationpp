#include <Terrain.h>

int Civilizationpp::Terrain::GetCombat() const
{
    return m_Combat;
}
Civilizationpp::Terrain::Terrain()
    : m_Category(BaseTerrain::Open),
      m_Name(TerrainName::Plains)
{
    m_Movement = 0;
    m_Combat = 0;
}
int Civilizationpp::Terrain::GetMovement() const
{
    return m_Movement;
}

Civilizationpp::Resource* Civilizationpp::Terrain::GetResource() const
{
    return m_Resource;
}
void Civilizationpp::Terrain::ChangeResource(Resource* resource)
{
    m_Resource = resource;
}
Civilizationpp::BaseTerrain Civilizationpp::Terrain::GetCategory() const
{
    return m_Category;
}
Civilizationpp::TerrainName Civilizationpp::Terrain::GetName() const
{
    return m_Name;
}
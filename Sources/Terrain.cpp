#include <Terrain.h>

int Civilizationpp::Terrain::GetCombat() const { return m_Combat; }

int Civilizationpp::Terrain::GetMovement() const { return m_Movement; }

Civilizationpp::Resource Civilizationpp::Terrain::GetResource() const {
    return m_Resource;
}
Civilizationpp::BasicTerrain Civilizationpp::Terrain::GetCategory() const {
    return m_Category;
}
Civilizationpp::TerrainName Civilizationpp::Terrain::GetName() const {
    return m_Name;
}
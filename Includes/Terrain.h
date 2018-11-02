#ifndef CIVILAZATIONPP_TERRAIN
#define CIVILAZATIONPP_TERRAIN

#include <Resource.h>

namespace Civilizationpp
{
enum class BaseTerrain
{
    Open,
    Rough,
    Lake,
    Coast,
    Ocean,
    Fresh_Water
};
enum class TerrainName
{
    Coast,
    Desert,
    GrassLand,
    Hill,
    Mountain,
    Ocean,
    Plains,
    Snow,
    Tundra,
    Forest,
    Jungle,
    Marsh,
    Atoll,
    FloodPlains,
    Ice,
    LAkes,
    Oasis
};
struct Terrain
{
 private:
    BaseTerrain m_category;
    TerrainName m_name;
    int m_movement;
    int m_combat;  // percent
    Resource* m_pResource;

 public:
    Terrain();
    BaseTerrain GetCategory() const;
    TerrainName GetName() const;
    int GetMovement() const;
    int GetCombat() const;
    Resource* GetResource() const;
    void ChangeResource(Resource* resource);
};
}  // namespace Civilizationpp

#endif  // CIVILAZATIONPP_TERRAIN
#ifndef CIVILAZATIONPP_TERRAIN
#define CIVILAZATIONPP_TERRAIN

#include <Resource.h>

namespace Civilizationpp {
enum class BasicTerrain { Open, Rough, Lake, Coast, Ocean, Fresh_Water };
enum class TerrainName {
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
struct Terrain {
 private:
    BasicTerrain m_Category;
    TerrainName m_Name;
    int m_Movement;
    int m_Combat;  // percent
    Resource m_Resource;

 public:
    BasicTerrain GetCategory() const;
    TerrainName GetName() const;
    int GetMovement() const;
    int GetCombat() const;
    Resource GetResource() const;
    void ChangeResource(Resource* resource);
};
}  // namespace Civilizationpp

#endif  // CIVILAZATIONPP_TERRAIN
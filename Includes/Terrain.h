#ifndef CIVILIZATIONPP_TERRAIN_H
#define CIVILIZATIONPP_TERRAIN_H

#include <BasicResource.h>

namespace Civilizationpp
{
enum class BaseTerrain
{
    Open,
    Rough,
    Lake,
    Coast,
    Ocean,
    FreshWater
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

class Terrain
{
 public:
    Terrain();

    BaseTerrain GetCategory() const;
    TerrainName GetName() const;
    int GetMovement() const;
    int GetCombat() const;
    BasicResource* GetResource() const;
    void ChangeResource(BasicResource* resource);

 private:
    BaseTerrain m_category;
    TerrainName m_name;
    int m_movement;
    int m_combat;
    BasicResource* m_pBasicResource;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_TERRAIN_H
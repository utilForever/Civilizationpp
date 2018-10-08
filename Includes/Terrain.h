#ifndef CIVILAZATIONPP_TERRAIN
#define CIVILAZATIONPP_TERRAIN

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
    BasicTerrain category;
    TerrainName name;
    int Movement;
	int combat; //percent

};
}  // namespace Civilizationpp

#endif  // CIVILAZATIONPP_TERRAIN
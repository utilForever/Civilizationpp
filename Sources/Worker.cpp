#include <Worker.h>

using namespace Civilizationpp;
void Worker::Build(Resource* tile) {
    auto [x, y] = GetPosition();
    
	m_map->GetTile(x, y)->ChangeResource(tile);
}
void Worker::Build(HexTile* tile, Resource* f) {}
Worker::Worker(HexMap* map, int x, int y) : BaseUnit(map, x, y) {}
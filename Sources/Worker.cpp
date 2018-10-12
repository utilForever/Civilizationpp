#include <Worker.h>

using namespace Civilizationpp;

Worker::Worker(int x, int y) : BaseUnit(x, y) {}

void Worker::Build(Resource* tile) {
    auto [x, y] = GetPosition();
    
	HexMap::GetInstance()->GetTile(x, y)->ChangeResource(tile);
}

void Worker::Build(HexTile* tile, Resource* f) {}

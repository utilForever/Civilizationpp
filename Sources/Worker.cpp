#include <Worker.h>

using namespace Civilizationpp;

Worker::Worker(int x, int y) : BaseUnit(x, y) {}

void Worker::Build(Resource* resource) {
    auto [x, y] = GetPosition();
    
	HexMap::GetInstance()->GetTile(x, y)->ChangeResource(resource);
}

void Worker::Build(HexTile* tile, Resource* resource)
{
    tile->ChangeResource(resource);
}

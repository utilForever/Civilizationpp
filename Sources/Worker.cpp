#include <Worker.h>

using namespace Civilizationpp;

Worker::Worker(int x, int y) : BaseUnit(x, y)
{
}

void Worker::Build(Resource* resource)
{
    auto position = GetPosition();
    HexMap::GetInstance()
        ->GetTile(position.first, position.second)
        ->ChangeResource(resource);
}

void Worker::Build(HexTile* tile, Resource* resource)
{
    tile->ChangeResource(resource);
}

#include <Worker.h>

using namespace Civilizationpp;

Worker::Worker(int x, int y) : BaseUnit(x, y)
{
    // Do nothing
}

void Worker::Build(BaseResource* resource)
{
    auto position = GetPosition();
    HexMap::GetInstance()
        ->GetTile(position.first, position.second)
        ->ChangeResource(resource);
}

void Worker::Build(HexTile* tile, BaseResource* resource)
{
    tile->ChangeResource(resource);
}

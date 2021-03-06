#include <Worker.h>

using namespace Civilizationpp;

Worker::Worker(int x, int y) : BaseUnit(x, y)
{
    // Do nothing
}

void Worker::Build(BasicResource* resource)
{
    auto position = GetPosition();
    HexMap::GetInstance()
        ->GetTile(position.first, position.second)
        ->ChangeResource(resource);
}

void Worker::Build(HexTile* tile, BasicResource* resource)
{
    tile->ChangeResource(resource);
}

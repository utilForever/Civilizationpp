#include <Worker.h>

using namespace Civilizationpp;
void Worker::Build(Obtainable* tile) {
    tile->ChangeFood([]() -> int { return 1; });
}
void Worker::Build(Obtainable* tile, eventFunction f) { tile->ChangeFood(f); }
Worker::Worker(int x, int y) : BaseUnit(x, y) {}
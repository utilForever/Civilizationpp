#include <Worker.h>
using namespace Civilizationpp;
void Worker::Build(Obtainable* tile) { 
	tile->ChangeFood([](HexTile t)->int { return 1; });
}
void Worker::Build(Obtainable* tile, eventFunction f) {
    tile->ChangeFood(f);
}
Worker::Worker(int x, int y) : BaseUnit(x,y) {

}
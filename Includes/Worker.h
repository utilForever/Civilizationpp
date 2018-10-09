#ifndef CIVILIZATIONPP_WORKER
#define CIVILIZATIONPP_WORKER

#include <BaseUnit.h>
#include <Material.h>

namespace Civilizationpp {
class Worker : public BaseUnit {
 public:
    Worker(int x, int y);
    void Build(Resource tile);
    void Build(HexTile* tile, Resource resource);
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_WORKER
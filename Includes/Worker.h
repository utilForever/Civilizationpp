#ifndef CIVILIZATIONPP_WORKER_H
#define CIVILIZATIONPP_WORKER_H

#include <BaseUnit.h>

namespace Civilizationpp
{
class Worker : public BaseUnit
{
 public:
    Worker(int x, int y);

    void Build(BaseResource* tile);
    void Build(HexTile* tile, BaseResource* resource);
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_WORKER_H
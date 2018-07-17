#pragma once
#include <BaseUnit.h>
#include <Material.h>

namespace Civilizationpp {
	class Worker : public BaseUnit{
	public:
        Worker(int x, int y);
           void Build(Obtainable* tile);
           void Build(Obtainable* tile, eventFunction f);
	};
}  // namespace Civilizationpp
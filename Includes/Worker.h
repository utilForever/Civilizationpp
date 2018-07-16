#include <BaseUnit.h>
#include <Material.h>

namespace Civilizationpp {
	class Worker : public BaseUnit{
	public:
        void Build(Obtainable* tile);
	};
}  // namespace Civilizationpp
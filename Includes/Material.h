#pragma once
#include <HexTile.h>
#include <functional>
namespace Civilizationpp {
using eventFunction = std::function<int(HexTile)>;
	class Obtainable {
	 protected:
            eventFunction Food;
            eventFunction Production;
            eventFunction Gold;
	 public:
            Obtainable();
			virtual int GetFood() = 0;
			virtual int GetProduction() = 0;
			virtual int GetGold() = 0;
			void ChangeFood(eventFunction f) noexcept;
            void ChangeProduction(eventFunction f) noexcept;
            void ChangeGold(eventFunction f) noexcept;
    };
}

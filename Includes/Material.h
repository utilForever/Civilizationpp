#ifndef CIVILIZATIONPP_OBTAINABLE
#define CIVILIZATIONPP_OBTAINABLE

#include <HexTile.h>
#include <functional>

namespace Civilizationpp {
//deprecated interface
using eventFunction = std::function<int()>;
class Obtainable {
 protected:
    [[deprecated]] eventFunction Food;
    [[deprecated]] eventFunction Production;
    [[deprecated]] eventFunction Gold;

 public:
    [[deprecated]] Obtainable();
    [[deprecated]] virtual int GetFood() = 0;
    [[deprecated]] virtual int GetProduction() = 0;
    [[deprecated]] virtual int GetGold() = 0;
    [[deprecated]] void ChangeFood(eventFunction f) noexcept;
    [[deprecated]] void ChangeProduction(eventFunction f) noexcept;
    [[deprecated]] void ChangeGold(eventFunction f) noexcept;
};
}  // namespace Civilizationpp
#endif  // CIVILIZATIONPP_OBTAINABLE
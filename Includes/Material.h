#ifndef CIVILIZATIONPP_OBTAINABLE
#define CIVILIZATIONPP_OBTAINABLE

#include <HexTile.h>
#include <functional>

namespace Civilizationpp {
using eventFunction = std::function<int()>;
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
}  // namespace Civilizationpp
#endif  // CIVILIZATIONPP_OBTAINABLE
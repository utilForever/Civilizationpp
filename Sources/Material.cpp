#include <Material.h>
using namespace Civilizationpp;
Obtainable::Obtainable() {
    Food = [](HexTile t) -> int { return 0; };
    Production = [](HexTile  t) -> int { return 0; };
    Gold = [](HexTile  t) -> int { return 0; };
}
void Obtainable::ChangeFood(eventFunction f) noexcept {
    Food = f;
}
void Obtainable::ChangeProduction(eventFunction f) noexcept {
    Production = f;
}
void Obtainable::ChangeGold(eventFunction f) noexcept {
    Gold = f;
}
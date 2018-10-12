#ifndef CIVILIZATIONPP_GAME_SETTINGS_H
#define CIVILIZATIONPP_GAME_SETTINGS_H

#include <cstddef>

namespace Civilizationpp
{
struct GameSettings
{
    GameSettings(std::size_t rowCount, std::size_t colCount);

    std::size_t rowCount;
    std::size_t colCount;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_GAME_SETTINGS_H
#ifndef CIVILIZATIONPP_GAME_SETTINGS_H
#define CIVILIZATIONPP_GAME_SETTINGS_H

namespace Civilizationpp
{
    struct GameSettings
    {
        GameSettings(int rowCount, int colCount);

        int rowCount;
        int colCount;
    };
}

#endif //CIVILIZATIONPP_GAME_SETTINGS_H
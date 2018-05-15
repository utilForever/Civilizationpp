#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

struct GameSettings
{
    GameSettings(int rowCount, int colCount);

    int rowCount;
    int colCount;
};

#endif //GAME_SETTINGS_H
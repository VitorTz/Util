#pragma once
#include "util/SceneId.hpp"


#define ASSETS_PATH "./src/assets/"
// #define ASSETS_PATH "./assets/"


namespace pk {

    constexpr float SCREEN_W{1280.0f};
    constexpr float SCREEN_H{720.0f};
    constexpr char WINDOW_TITLE[]{"PokemonRpg"};
    constexpr int FPS{60};

    constexpr pk::SceneID MAIN_SCENE{pk::TitleScreenId};
    constexpr char WINDOW_ICON[]{ASSETS_PATH "RaylibLogo.png"};

}
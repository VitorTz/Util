#include <raylib.h>
#include "constants.hpp"
#include "util/AssetPool.hpp"
#include "util/AssetPool.hpp"
#include "scene/Scene.hpp"


#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


void mainloop() {
    pk::gSceneManager.update(GetFrameTime());
    BeginDrawing();
    ClearBackground(BLACK);
    pk::gSceneManager.draw();
    EndDrawing();
}


int main() {
    InitWindow(pk::SCREEN_W, pk::SCREEN_H, pk::WINDOW_TITLE);
    const Image iconImage = LoadImage(pk::WINDOW_ICON);
    SetWindowIcon(iconImage);
    
    pk::gSceneManager.init();

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(mainloop, 60, 1);
    #else
        SetTargetFPS(60);    
        while (!WindowShouldClose()) {
            mainloop();
        }
    #endif

    UnloadImage(iconImage);
    pk::gAssetPool.clear();
    CloseWindow();
    return 0;
}
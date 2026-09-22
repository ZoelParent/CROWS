#include "game.h"
#include "raylib.h"
#include "resource_dir.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "CROWS SIMULATOR");
    SetTargetFPS(30);
    SearchAndSetResourceDir("resources");


    Texture ACV = LoadTexture("ACV.png");
    Texture ZBD = LoadTexture("ZBD.png");

    GameState g;
    g.ACV_Texture = ACV;
    g.ZBD_Texture = ZBD;
    g.width = 800;
    g.height = 600;
    g.ACV.weaponActive = true;

    initGame(&g);
    gameLoop(&g);

    UnloadTexture(ACV);
    CloseWindow();

    return 0;
}

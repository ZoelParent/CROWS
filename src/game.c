#include "game.h"
#include "aimbot.h"
#include "point.h"
#include "raylib.h"
#include "vehicle.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

void tryMoveVehicle(int width, int height, Vehicle *v) {
    int upDown = rand() % 21 - 10;
    int leftRight = rand() % 21 - 10;

    int newxPos = v->location.x + leftRight;
    int newyPos = v->location.y + upDown;

    if (newxPos > width || newxPos < 0)
        return;
    if(newyPos > height || newyPos < 0)
        return;

    v->location.x = newxPos;
    v->location.y = newyPos;
}

void renderGameState(GameState *g) {
    BeginDrawing();

    ClearBackground((Color) {158, 112, 20, 100});
    DrawTexture(g->ACV_Texture, g->ACV.location.x, g->ACV.location.y, WHITE);

    // Flip ACV depending location of ZBD
    /***********************************************************************************/
    /* if (g->ACV.location.x < g->ZBD.location.x) {                                    */
    /*     Rectangle source = {0, 0, -128, 128};                                       */
    /*     Rectangle dest = {g->ACV.location.x, g->ACV.location.y, 128, 128};          */
    /*     DrawTexturePro(g->ACV_Texture, source, dest, (Vector2){0, 0}, 0.0f, WHITE); */
    /* }                                                                               */
    /***********************************************************************************/

    DrawTexture(g->ACV_Texture, g->ACV.location.x, g->ACV.location.y, WHITE);
    DrawTexture(g->ZBD_Texture, g->ZBD.location.x, g->ZBD.location.y, WHITE);

    if(g->ACV.weaponActive) {
        double distance = calcPointDistance(g->ACV.location, g->ZBD.location);

        //Get each component
        int deltaY = (int) (sin(g->ACV.weaponHeading) * distance);
        int deltaX = (int) (cos(g->ACV.weaponHeading) * distance);

        //Correct for PNG sprite turret locations.
        DrawLine(g->ACV.location.x + 40, g->ACV.location.y + 50,
                 g->ACV.location.x + deltaX + 64,
                 g->ACV.location.y + deltaY + 64,
                 WHITE);
    }

    EndDrawing();
};

void stepState(GameState *g) {
    //DRAW VEHICLES
    renderGameState(g);

    //UPDATE VEHICLES
    tryMoveVehicle(g->width, g->height, &g->ACV);
    tryMoveVehicle(g->width, g->height, &g->ZBD);
    double newHeading = calcHeading(g->ACV, g->ZBD);
    g->ACV.weaponHeading = newHeading;
}

void spawnVehicles(GameState *g) {
    g->ACV.location.x = (g->width / 2);
    g->ACV.location.y = (g->height / 2);

    g->ZBD.location.x = g->width / 4;
    g->ZBD.location.y = g ->height / 4;
}

void initGame(GameState *g) {
    srand(time(NULL));
    spawnVehicles(g);
}

void gameLoop(GameState *g) {
    while (!WindowShouldClose()) {
        stepState(g);
    }
}

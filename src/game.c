#include "game.h"
#include "aimbot.h"
#include "point.h"
#include "raylib.h"
#include "vehicle.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

void tryMoveVehicle(int width, int height, Vehicle *v) {
    int upDown = rand() % 7 - 3;
    int leftRight = rand() % 7 - 3;

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
    DrawTexture(g->ZBD_Texture, g->ZBD.location.x, g->ZBD.location.y, WHITE);

    if(g->ACV.weaponActive) {
        double distance = calcPointDistance(g->ACV.location, g->ZBD.location);

        //Get each component
        int deltaX = (int) sin(g->ACV.weaponHeading) * distance;
        int deltaY = (int) cos(g->ACV.weaponHeading) * distance;

        int endPosX = g->ZBD.location.x + deltaX;
        int endPosY = g->ZBD.location.y + deltaY;

        //Correct for PNG sprite turret locations.
        DrawLine(g->ACV.location.x + 40, g->ACV.location.y + 50, endPosX + 64, endPosY + 64, RED);
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

    int randomX = rand() % g->width + 1;
    int randomY = rand() % g->height + 1;

    g->ZBD.location = (Point) {randomX, randomY};
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

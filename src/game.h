#ifndef GAME_H_
#define GAME_H_

#include "raylib.h"
#include "vehicle.h"
#include "point.h"
#include <stdlib.h>

typedef struct GameState {
    int width;
    int height;

    Vehicle ACV;
    Vehicle ZBD;
                                                \
    Texture ACV_Texture;
    Texture ZBD_Texture;
} GameState;

void tryMoveVehicle(int width, int height, Vehicle *v);

void stepState(GameState *g);

void initGame(GameState *g);

void gameLoop(GameState *g);

#endif // GAME_H_

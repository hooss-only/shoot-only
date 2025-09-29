#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "player.h"

struct planet {
        bool existance;
        SDL_Rect rect;
        float x, y;
        double rotation;
        SDL_Renderer* renderer;
        int type;

        struct player* player;
};

void init_planet(struct planet* self, SDL_Renderer* renderer, struct player* player);
void tick_planet(struct planet* self, float dt);
void render_planet(struct planet* self);

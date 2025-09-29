#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "player.h"

struct score {
        bool existance;
        SDL_Rect rect;
        float x, y, speed;
        double rotation;
        SDL_Renderer* renderer;
        int type;

        struct player* player;
};

void init_score(struct score* self, SDL_Renderer* renderer, struct player* player);
void tick_score(struct score* self, float dt);
void render_score(struct score* self);

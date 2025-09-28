#pragma once
#include <SDL2/SDL.h>

struct star {
        float scale, x, y;
        double angle;
        SDL_Rect rect;
        SDL_Renderer* renderer;
};

void init_star(struct star* self, SDL_Renderer* renderer);
void tick_star(struct star* self, float dt);
void render_star(struct star* self);

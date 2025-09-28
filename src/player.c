#include "player.h"
#include "utils/logger.h"

#include <SDL2/SDL_image.h>


void init_player(struct player* self, SDL_Renderer* renderer) {
        self->renderer = renderer;
        self->x = 0;
        self->y = 0;
        self->rect.x = 0;
        self->rect.y = 0;
        self->rect.w = 4 * 4;
        self->rect.h = 4 * 4;
        self->texture = IMG_LoadTexture(self->renderer, "./assets/player.png");

        self->vx = 0;
        self->vy = 0;
}

void tick_player(struct player* self, float dt) {
        self->x += self->vx * dt;
        self->y += self->vy * dt;
}

void render_player(struct player* self) {
        self->rect.x = (int) self->x;
        self->rect.y = (int) self->y;
        SDL_RenderCopy(self->renderer, self->texture, NULL, &self->rect);
}

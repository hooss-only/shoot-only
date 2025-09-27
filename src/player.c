#include "player.h"

#include <SDL2/SDL_image.h>


void init_player(struct player* self, SDL_Renderer* renderer) {
        self->renderer = renderer;
        self->rect.x = 0;
        self->rect.y = 0;
        self->rect.w = 4 * 4;
        self->rect.h = 4 * 4;
        self->texture = IMG_LoadTexture(self->renderer, "./assets/player.png");
}

void render_player(struct player* self) {
        SDL_RenderCopy(self->renderer, self->texture, NULL, &self->rect);
}

#include "star.h"
#include "textures.h"

#include <stdlib.h>

#define STAR_SPEED 80

void init_star(struct star* self, SDL_Renderer* renderer) {
        self->renderer = renderer;
        self->x = rand() % 800;
        self->y = rand() % 600;
        
        self->scale = rand() / (float) RAND_MAX;

        self->angle = (double) (rand() % 360);

        self->rect.w = (int) (16 * self->scale);
        self->rect.h = (int) (16 * self->scale);
}

void tick_star(struct star* self, float dt) {
        self->y += STAR_SPEED * self->scale * dt;

        if (self->y > 600) {
                self->x = rand() % 800;
                self->y = (rand() % 50) * -1;

                self->scale = rand() / (float) RAND_MAX;

                self->rect.w = (int) (16 * self->scale);
                self->rect.h = (int) (16 * self->scale);

                self->angle = (double) (rand() % 360);
        }
}

void render_star(struct star* self) {
        self->rect.x = self->x;
        self->rect.y = self->y;
        SDL_SetTextureAlphaMod(star_texture, 128);
        SDL_RenderCopyEx(self->renderer, star_texture, NULL, &self->rect, self->angle, NULL, SDL_FLIP_NONE);
}

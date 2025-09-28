#include "missile.h"

#include "textures.h"

void init_missile(struct missile* self, SDL_Renderer* renderer) {
        self->renderer = renderer;
        self->existance = true;
        self->x = 0;
        self->y = 0;
        self->speed = 300;

        self->rect.w = 2*4;
        self->rect.h = 2*4;
}

void tick_missile(struct missile* self, float dt) {
        self->y -= self->speed * dt;

        if (self->y < 0) {
                self->existance = false;
        }
}

void render_missile(struct missile* self) {
        self->rect.x = self->x;
        self->rect.y = self->y;
        SDL_RenderCopy(self->renderer, missile_texture, NULL, &self->rect);
}

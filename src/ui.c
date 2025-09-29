#include "ui.h"

#include "textures.h"

struct player* ui_player;

void set_ui_player(struct player *player) {
        ui_player = player;
}

void render_heart(SDL_Renderer* renderer) {
        const int x = 2, y = 2;
        for (int i=0; i<MAX_HP; i++) {
                SDL_Rect rect = {x + (30 * i), y, 7 * 4, 6 * 4};
                SDL_Texture* texture = ui_player->hp - i > 0 ?
                        heart_filled_texture : heart_container_texture;
                SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
}

void render_ui(SDL_Renderer* renderer) {
        render_heart(renderer);
}

void tick_ui(float dt) {
}

#pragma once

#include <SDL2/SDL.h>
#include "player.h"

void set_ui_player(struct player* player);
void render_ui(SDL_Renderer* renderer);
void tick_ui(float dt);

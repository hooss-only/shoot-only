#include <SDL2/SDL.h>
#include <stdbool.h>

#include "textures.h"
#include "player.h"
#include "utils/logger.h"

#include "missiles.h"
#include "star.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

struct player player;
#define STAR_AMOUNT 100
struct star background_star[STAR_AMOUNT];

void init_game(SDL_Renderer* renderer);

void handle_event(SDL_Event* e);

void tick(float dt);

void render(SDL_Renderer* renderer);

void destroy();

int main(int argc, char* argv[]) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                return 0;
        }
        
        SDL_Window *window = SDL_CreateWindow("shoot-only", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (!window) {
                return 0;
        } else {
                SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

                if (!renderer) {
                        return 0;
                } else {
                        init_game(renderer);
                        bool running = true;
                        SDL_Event e;
                        double dt = 0.f;
                        Uint32 last_time = SDL_GetTicks();

                        while (running) {
                                Uint32 current_time = SDL_GetTicks();
                                float dt = (current_time - last_time) / 1000.f;
                                last_time = current_time;
                                
                                while (SDL_PollEvent(&e)) {
                                        if(e.type == SDL_QUIT) {
                                                running = false;
                                        }
                                        handle_event(&e);
                                }

                                tick(dt);
                                
                                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                                SDL_RenderClear(renderer);
                                
                                render(renderer);
                                
                                SDL_RenderPresent(renderer);
                        }
                        destroy();

                        SDL_DestroyRenderer(renderer);
                }
                SDL_DestroyWindow(window);
        }
        SDL_Quit();

        return 0;
}

void init_game(SDL_Renderer* renderer) {
        LOG_set_level(LOG_DEBUG);
        LOG_printf(LOG_NORMAL, "Initiate game\n");
        init_textures(renderer);
        set_missiles_renderer(renderer);
        init_player(&player, renderer);

        for (int i=0; i<STAR_AMOUNT; i++) {
                init_star(&background_star[i], renderer);
        }
}

void handle_event(SDL_Event* e) {
        handle_player_event(&player, e);
}

void tick(float dt) {
        tick_player(&player, dt);
        tick_missiles(dt);

        for (int i=0; i<STAR_AMOUNT; i++) {
                tick_star(&background_star[i], dt);
        }
}

void render(SDL_Renderer* renderer) {
        render_player(&player);
        render_missiles();
        
        for (int i=0; i<STAR_AMOUNT; i++) {
                render_star(&background_star[i]);
        }
}

void destroy() {
        destroy_player(&player);
        destroy_textures();
}

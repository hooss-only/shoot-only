#include <SDL2/SDL.h>
#include <stdbool.h>
#include "utils/logger.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]) {
        LOG_set_level(LOG_DEBUG);
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                return 0;
        }
        
        SDL_Window *window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (!window) {
                return 0;
        } else {
                SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

                if (!renderer) {
                        return 0;
                } else {
                        bool running = true;
                        while (running) {
                                SDL_Event e;

                                SDL_WaitEvent(&e);
                                
                                if (e.type == SDL_QUIT) {
                                        running = false;
                                }
                                
                                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                                SDL_RenderClear(renderer);
                                
                                SDL_RenderPresent(renderer);
                        }

                        SDL_DestroyRenderer(renderer);
                }
                SDL_DestroyWindow(window);
        }
        SDL_Quit();

        return 0;
}

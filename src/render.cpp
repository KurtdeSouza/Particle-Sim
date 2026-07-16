#include <SDL2/SDL.h>
#include <stdio.h>
#include "Particle.h"
#include <vector>
#include <random>
#include <iostream>
#include "constants.h"
#include "Grid.h"
#include "Cell.h"

int main(int argc, char* argv[]) {
    // 0. init simulation parameters:
    std::vector<Cell> c{};
    Grid grid(c);
    std::vector<Particle> particles = grid.particle_init_rand();

    // 1. Initialize SDL Video Subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // 2. Create the Window
    SDL_Window* window = SDL_CreateWindow(
        "Blank SDL2 Window",        // Window title
        SDL_WINDOWPOS_CENTERED,     // Initial x position
        SDL_WINDOWPOS_CENTERED,     // Initial y position
        Consts::WIDTH,                        // Width, in pixels
        Consts::HEIGHT,                        // Height, in pixels
        SDL_WINDOW_SHOWN            // Flags (makes the window visible)
    );

    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // 3. Create the Renderer to clear the screen
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 4. The Event and Main Loop
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        // Handle events in the queue (e.g., clicking the 'X' button)
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Set background color to Black (RGBA: 0, 0, 0, 255)
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        // Clear the screen with the chosen color
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //this should be done in grid class
        // also should iterate by cell
        /*
        1. make grid instance
        2. make particle vector
        3. make cells with a given apothem to cover entire grid space assigning each cell its center, neighbor will have prev center + 2 * apothem
        4. iterate over particle list and assign the particle to the correct cell
        5. during render update iterate over cell list and compute collisions
        
        
        
        
        */
        for(Particle& p : particles){
            p.speed_update();
            if(p.bounce_check_x()){
                p.bounce_x();
            }
            if(p.bounce_check_y()){
                p.bounce_y();
            }
            SDL_RenderDrawPoint(renderer, p.get_pos_x(), p.get_pos_y());

        }
        // Update the screen with the rendering actions
        SDL_RenderPresent(renderer);
    }

    // 5. Clean up and Resource Management
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
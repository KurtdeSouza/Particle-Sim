#pragma once
#include "Cell.h"
#include <vector>
#include "constants.h"
#include <SDL2/SDL.h>

class Grid{
private:
    std::vector<Cell> cells;
    int width = Consts::WIDTH;
    int height = Consts::HEIGHT;
    std::vector<Particle> particles;
public:
    Grid(std::vector<Cell> cells, std::vector<Particle> new_particles);
    void set_cells(std::vector<Cell> new_cells);
    void set_particle_init_rand(std::vector<Particle> new_p);
    void update(SDL_Renderer* renderer);
    void draw_circle(Particle p, SDL_Renderer* renderer );
    
};


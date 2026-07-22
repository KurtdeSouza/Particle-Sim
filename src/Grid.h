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
    Grid(std::vector<Cell> cells, std::vector<Particle> new_particles, int number_particles);
    void set_cells(std::vector<Cell> new_cells);
    void set_particle_init_rand(std::vector<Particle> new_p, int num_particles);
    void update(SDL_Renderer* renderer, uint64_t tick, uint64_t prev_tick);
    void draw_circle(Particle p, SDL_Renderer* renderer );
    void brute_force_particle_collision();
    void custom_particle_init(std::vector<Particle> new_p);
};


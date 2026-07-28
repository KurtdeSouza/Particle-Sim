#pragma once
#include "Cell.h"
#include <vector>
#include "constants.h"
#include <SDL2/SDL.h>
#include <unordered_map>

class Grid{
private:
    std::unordered_map<int, Cell> cells;
    int width = Consts::WIDTH;
    int height = Consts::HEIGHT;
    std::vector<Particle> particles;
    int cell_length = Consts::SIDE_LENGTH;
public:
    Grid(std::unordered_map<int, Cell> cells, std::vector<Particle> new_particles, int number_particles);
    void set_cells_init(std::unordered_map<int, Cell> new_cells);
    void set_particle_init_rand(std::vector<Particle> new_p, int num_particles);
    void update(SDL_Renderer* renderer, uint64_t tick, uint64_t prev_tick);
    void draw_circle(Particle p, SDL_Renderer* renderer );
    void brute_force_particle_collision();
    void custom_particle_init(std::vector<Particle> new_p);
    int get_cell_length();
    std::pair<int, int> get_closest_cell(std::pair<int, int> part_coords);
    void populate_cells();
    void cell_sweep_collision();
    void cell_collision();
    int cell_hash(std::pair<int, int> coords);
    std::pair<int, int> unhash(int hashed);

};


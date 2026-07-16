#include "Particle.h"
#include <iostream>
#include "constants.h"
#include "Cell.h"
#include "Grid.h"
#include <random>

Grid::Grid(std::vector<Cell> cells){
    set_cells(cells);
}
void Grid::set_cells(std::vector<Cell> new_cells){
    cells = new_cells;
}
std::vector<Particle> Grid:: particle_init_rand(){
        // make random particle list
    float min_val = -3.0f;
    float max_val = 3.0f;
    int max_height = Consts::WIDTH;
    int max_width = Consts::HEIGHT;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distr(min_val, max_val);
    std::uniform_int_distribution<int> distr_X(0, max_height);
    std::uniform_int_distribution<int> distr_Y(0, max_width);

    float random_num_x, random_num_y;
    int rand_x, rand_y;
    std::vector<Particle> particles;
    for(int i = 0; i < 1; i++){
        random_num_x = distr(gen);
        random_num_y = distr(gen);
        rand_x = distr_X(gen);
        rand_y = distr_Y(gen);
        particles.emplace_back(rand_x, rand_y, random_num_x, random_num_y);
    }
    return particles;
}
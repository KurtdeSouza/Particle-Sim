#pragma once
#include "Cell.h"
#include <vector>
#include "constants.h"
class Grid{
private:
    std::vector<Cell> cells;
    int width = Consts::WIDTH;
    int height = Consts::HEIGHT;
public:
    Grid(std::vector<Cell> cells);
    void set_cells(std::vector<Cell> new_cells);
    std::vector<Particle> particle_init_rand();

};


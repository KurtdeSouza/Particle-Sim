#pragma once
#include "Cell.h"
#include <vector>

class Grid{
private:
    std::vector<Cell> cells;
public:
    Grid(std::vector<Cell> cells);
//also include dimensions of the grid that come from constant
};


#pragma once
#include <cstdint>
#include <vector>
#include "Particle.h"
class Cell{
private:
    std::vector<Particle> particles;
    std::vector<Cell> neighbors;
    int side_length;
    std::vector<int> cell_coords; //maybe define as the top left corner of the cell so that we can just add side length to x and y to get bottom corner (math is easier)
public:
    Cell(int side_length, std::vector<int> cell_coords, std::vector<Particle> particles, std::vector<Cell> neighbors);
    void set_particles(std::vector<Particle> particles);
    void set_cell_coords(std::vector<int> cell_coords);
    void set_cell_neighbors(std::vector<Cell> cell_neihgbors);
    void set_side_length(int new_side_length);


};
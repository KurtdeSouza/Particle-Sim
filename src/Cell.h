#pragma once
#include <cstdint>
#include <vector>
#include "Particle.h"
class Cell{
private:
    std::vector<std::size_t> particles;
    std::vector<std::pair<int,int>> neighbors;
    int side_length;
    std::pair<int,int> cell_coords; //maybe define as the top left corner of the cell so that we can just add side length to x and y to get bottom corner (math is easier)
public:
    Cell(int side_length, std::pair<int, int> cell_coords, std::vector<std::size_t> particles, std::vector<std::pair<int, int>> neighbors);
    void set_particles(std::vector<std::size_t> particles);
    void set_cell_coords(std::pair<int, int> cell_coords);
    void set_cell_neighbors(std::vector<std::pair<int, int>> cell_neihgbors);
    void set_side_length(int new_side_length);


};
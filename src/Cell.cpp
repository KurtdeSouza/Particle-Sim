#include "Cell.h"
#include <iostream>
#include "constants.h"
#include <cmath>
#include "Particle.h"
Cell::Cell(int side_length, std::vector<int> cell_coords, std::vector<Particle> particles, std::vector<Cell> neighbors){
    set_particles(particles);
    set_cell_neighbors(neighbors);
    set_side_length(side_length);
    set_cell_coords(cell_coords);
    
}
void Cell::set_particles(std::vector<Particle> new_particles){
    particles = new_particles;
}
void Cell::set_cell_neighbors(std::vector<Cell> new_neighbors){
    neighbors = new_neighbors;
}
void Cell::set_cell_coords(std::vector<int> new_cell_coords){
    cell_coords = new_cell_coords;
}
void Cell::set_side_length(int new_side_length){
    side_length = new_side_length;
}

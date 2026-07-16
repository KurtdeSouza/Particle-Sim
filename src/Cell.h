#pragma once
#include <vector>
#include "Particle.h"
class Cell{
private:
    int pos_x;
    int pos_y;
    int apothem;
    std::vector<Particle> particles;
    std::vector<Cell> neighbors;
public:
    Cell(int pos_x, int pos_y, int apothem, std::vector<Particle> particles, std::vector<Cell> neighbors);
    void set_pos_x(int new_pos_x);
    void set_pos_y(int new_pos_y);
    void set_particle_list(std::vector<Particle> particles);
    void set_neighbor_cells(std::vector<Cell> neighbors);
    void set_apothem(int apothem);
    bool detect_collision(Particle p1, Particle p2);
    void compute_collision(Particle p1, Particle p2);
};


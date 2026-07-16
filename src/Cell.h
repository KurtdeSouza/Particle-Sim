#pragma once
#include <vector>
#include "Particle.h"
class Cell{
private:
    int pos_x;
    int pos_y;
    std::vector<Particle> particles;
    
public:
    Cell(int pos_x, int pos_y, std::vector<Particle> particles);
    void set_pos_x(int new_pos_x);
    void set_pos_y(int new_pos_y);
};


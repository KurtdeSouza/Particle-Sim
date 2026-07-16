#include "Cell.h"
#include <iostream>
#include "constants.h"
Cell::Cell(int pos_x, int pos_y, std::vector<Particle> particles){
    set_pos_x(pos_x);
    set_pos_y(pos_y);
}
void Cell::set_pos_x(int new_pos_x){
    pos_x = new_pos_x;
}
void Cell::set_pos_y(int new_pos_y){
    pos_y = new_pos_y;
}

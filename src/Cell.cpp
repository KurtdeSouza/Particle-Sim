#include "Cell.h"
#include <iostream>
#include "constants.h"
#include <cmath>
Cell::Cell(int pos_x, int pos_y, int apothem, std::vector<Particle> particles, std::vector<Cell> neighbors){
    set_pos_x(pos_x);
    set_pos_y(pos_y);
    set_particle_list(particles);
    set_neighbor_cells(neighbors);
    set_apothem(apothem);
}
void Cell::set_pos_x(int new_pos_x){
    pos_x = new_pos_x;
}
void Cell::set_pos_y(int new_pos_y){
    pos_y = new_pos_y;
}
void Cell::set_particle_list(std::vector<Particle> new_particles){
    particles = new_particles;
};
void Cell::set_neighbor_cells(std::vector<Cell> new_neighbors){
    neighbors = new_neighbors;
};
void Cell::set_apothem(int new_apothem){
    apothem = new_apothem;
}
//IMPORTANT: must check this thoroughly before moving on to other problems
bool detect_collision(Particle* p1, Particle* p2){
    if(std::abs(p1->get_pos_x() - p2->get_pos_x()) < 1 && std::abs(p1->get_pos_y() - p2->get_pos_y()) < 1 ){ //maybe add some boundary to this colision detection since the speed/cell radius gives some margin of error
        return true;
    }else{
        return false;
    }
}
//basic reflected collisison but can change later
void compute_collision(Particle *p1, Particle *p2){
    if(detect_collision(p1, p2)){
        p1->set_speed_x(-p1->get_speed_x());
        p1->set_speed_y(-p1->get_speed_y());
        p2->set_speed_x(-p2->get_speed_x());
        p2->set_speed_y(-p2->get_speed_y());
        //do stuff
    }else{
        return;
    }
}
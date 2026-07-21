#include "Particle.h"
#include <iostream>
#include "constants.h"

Particle::Particle(int pos_x, int pos_y, int radius, float speed_x, float speed_y){
    set_pos_x(pos_x);
    set_pos_y(pos_y);
    set_speed_x(speed_x);
    set_speed_y(speed_y);
    set_radius(radius);
    
}
void Particle::set_pos_x(int new_pos_x){
    pos_x = new_pos_x;
}
void Particle::set_pos_y(int new_pos_y){
    pos_y = new_pos_y;
}
void Particle::set_speed_x(float new_speed_x){
    speed_x = new_speed_x;
}
void Particle::set_speed_y(float new_speed_y){
    speed_y = new_speed_y;
}
void Particle::set_radius(int new_radius){
    radius = new_radius;
}
int Particle::get_pos_x(){
    return pos_x;
};
int Particle::get_radius(){
    return radius;
}

int Particle::get_pos_y(){
    return pos_y;
};
float Particle::get_speed_x(){
    return speed_x;
}
float Particle::get_speed_y(){
    return speed_y;
}
void Particle::speed_update(uint64_t delta){
    int new_pos_x = get_pos_x() + get_speed_x()*delta;
    int new_pos_y = get_pos_y() + get_speed_y()*delta;

    set_pos_x(new_pos_x);
    set_pos_y(new_pos_y);
}
bool Particle::bounce_check_x_wall(){
    if((get_pos_x() + get_radius() >= Consts::WIDTH && get_speed_x() > 0) || (get_pos_x() - get_radius() <= 0 && get_speed_x() < 0)){
        return true;
    }
    return false;
}
bool Particle::bounce_check_y_wall(){
    if((get_pos_y() + get_radius() >= Consts::HEIGHT && get_speed_y() > 0)|| (get_pos_y() - get_radius() <= 0 && get_speed_y() < 0)){
        return true;
    }
    return false;
}

void Particle::bounce_x(){
    std::cout << "X pos: " << get_pos_x() << "\n";
    set_speed_x(-get_speed_x());
}
void Particle::bounce_y(){
     std::cout << "Y pos: " << get_pos_y() << "\n";
    set_speed_y(-get_speed_y());
}



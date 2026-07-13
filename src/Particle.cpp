#include "Particle.h"
Particle::Particle(int pos_x, int pos_y, float speed_x, float speed_y){
    set_pos_x(pos_x);
    set_pos_y(pos_y);
    set_speed_x(speed_x);
    set_speed_y(speed_y);
    
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
int Particle::get_pos_x(){
    return pos_x;
};
int Particle::get_pos_y(){
    return pos_y;
};

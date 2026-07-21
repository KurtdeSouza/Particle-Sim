#include "Particle.h"
#include <iostream>
#include "constants.h"
#include <cmath>
Particle::Particle(float pos_x, float pos_y, int radius, float speed_x, float speed_y){
    set_pos_x(pos_x);
    set_pos_y(pos_y);
    set_speed_x(speed_x);
    set_speed_y(speed_y);
    set_radius(radius);
    
}
void Particle::set_pos_x(float new_pos_x){
    pos_x = new_pos_x;
}
void Particle::set_pos_y(float new_pos_y){
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
float Particle::get_pos_x(){
    return pos_x;
};
int Particle::get_radius(){
    return radius;
}

float Particle::get_pos_y(){
    return pos_y;
};
float Particle::get_speed_x(){
    return speed_x;
}
float Particle::get_speed_y(){
    return speed_y;
}
void Particle::speed_update(float delta){
    float new_pos_x = get_pos_x() + get_speed_x()*delta;
    float new_pos_y = get_pos_y() + get_speed_y()*delta;
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

void Particle::bounce_wall_x(){
    if(bounce_check_x_wall()){set_speed_x(-get_speed_x());}
}
void Particle::bounce_wall_y(){
    if(bounce_check_y_wall()){set_speed_y(-get_speed_y());}

}
std::vector<float> Particle::get_normal(Particle &p){
    float rel_x = p.get_pos_x() - get_pos_x();
    float rel_y = p.get_pos_y() - get_pos_y();
    float root = std::sqrt(std::pow(rel_x, 2) + std::pow(rel_y, 2)); //(691-636)^2 + (300-300)^2
    float norm_x = rel_x/root;
    float norm_y = rel_y/root;
    return {norm_x, norm_y};
}
std::vector<float> Particle::get_dot(Particle &p, std::vector<float> normal){
    float p1_n = (get_speed_x() * normal[0]) + (get_speed_y() * normal[1]);
    float p2_n = (p.get_speed_x() * normal[0]) + (p.get_speed_y() * normal[1]);

    return {p1_n, p2_n};
}
void Particle::collide(Particle &p){
    std::vector<float> normals = get_normal(p);
    std::vector<float> dots = get_dot(p, normals);
    float new_speed_x1 = get_speed_x() + (dots[1] - dots[0]) * (normals[0]);
    float new_speed_y1 = get_speed_y() + (dots[1] - dots[0]) * (normals[1]);
    float new_speed_x2 = p.get_speed_x() + (dots[0] - dots[1]) * (normals[0]);
    float new_speed_y2 = p.get_speed_y() + (dots[0] - dots[1]) * (normals[1]);
    set_speed_x(new_speed_x1);
    set_speed_y(new_speed_y1);
    p.set_speed_x(new_speed_x2);
    p.set_speed_y(new_speed_y2);

}
bool Particle::check_part_collision(Particle &p){
    float delta_x = std::abs(get_pos_x() - p.get_pos_x());
    float delta_y = std::abs(get_pos_y() - p.get_pos_y());

    float distance = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));
    float tot_radius = get_radius() + p.get_radius();
    if (tot_radius > distance){
        return true;
    }else{
        return false;
    }
}


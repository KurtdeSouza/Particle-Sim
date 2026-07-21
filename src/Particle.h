#pragma once
#include <cstdint>
#include <vector>
class Particle{
private:
    int pos_x;
    int pos_y;
    float speed_x;
    float speed_y;
    int radius;
public:
    Particle(int pos_x, int pos_y, int radius, float speed_x, float speed_y);
    void set_pos_x(int new_pos_x);
    void set_pos_y(int new_pos_y);
    void set_speed_x(float new_speed_x);
    void set_speed_y(float new_speed_y);
    int get_pos_x();
    int get_pos_y();
    float get_speed_x();
    float get_speed_y();
    void speed_update(uint64_t tick);
    bool bounce_check_x_wall();
    bool bounce_check_y_wall();
    void bounce_x();
    void bounce_y();
    void set_radius(int new_radius);
    int get_radius();

};


#pragma once
#include <cstdint>
#include <vector>
class Particle{
private:
    float pos_x;
    float pos_y;
    float speed_x;
    float speed_y;
    int radius;
public:
    Particle(float pos_x, float pos_y, int radius, float speed_x, float speed_y);
    void set_pos_x(float new_pos_x);
    void set_pos_y(float new_pos_y);
    void set_speed_x(float new_speed_x);
    void set_speed_y(float new_speed_y);
    float get_pos_x();
    float get_pos_y();
    float get_speed_x();
    float get_speed_y();
    void speed_update(float tick);
    bool bounce_check_x_wall();
    bool bounce_check_y_wall();
    void bounce_wall_x();
    void bounce_wall_y();
    void set_radius(int new_radius);
    int get_radius();
    std::vector<float> get_normal(Particle &p);
    std::vector<float> get_dot(Particle &p, std::vector<float> normal);
    void collide(Particle &p);
    bool check_part_collision(Particle &p);
    void position_correction(Particle& p, std::vector<float> normals);
    float calc_distance(Particle &p);
    float calc_radius_diff(Particle &p);
};


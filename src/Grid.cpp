#include "Particle.h"
#include <iostream>
#include "constants.h"
#include "Cell.h"
#include "Grid.h"
#include <random>

Grid::Grid(std::vector<Cell> cells, std::vector<Particle> particles, int num_particles){
    set_cells(cells);
    set_particle_init_rand(particles, num_particles);
    //custom_particle_init(particles);
}
void Grid::set_cells(std::vector<Cell> new_cells){
    cells = new_cells;
}
void Grid:: set_particle_init_rand(std::vector<Particle> new_p, int num_particles){
    float min_val = -3.0f;
    float max_val = 3.0f;
    int max_height = Consts::WIDTH;
    int max_width = Consts::HEIGHT;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distr(min_val, max_val);
    std::uniform_int_distribution<int> distr_X(0, max_height);
    std::uniform_int_distribution<int> distr_Y(0, max_width);
    int radius = 10;
    float random_num_x, random_num_y;
    int rand_x, rand_y;
    for(int i = 0; i < num_particles; i++){
        random_num_x = distr(gen) * 100;
        random_num_y = distr(gen) * 100;
        rand_x = distr_X(gen);
        rand_y = distr_Y(gen);
        new_p.emplace_back(rand_x, rand_y, radius, random_num_x, random_num_y);
    }
    particles = new_p;
}
void Grid:: custom_particle_init(std::vector<Particle> new_p){
        // make custom particles to collide/test
    new_p.emplace_back(300, 300, 20, 1000, 0);

    new_p.emplace_back(600, 300, 40, -1000, 0);

    particles = new_p;
}
void Grid::draw_circle(Particle p, SDL_Renderer* renderer ){
    //std::cout << p.get_pos_x();
    int y0 = static_cast<int>(p.get_pos_y());
    int x0 = static_cast<int>(p.get_pos_x());
    int radius = p.get_radius();
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
        SDL_RenderDrawPoint(renderer,x0 + y, y0 + x);
        SDL_RenderDrawPoint(renderer,x0 - y, y0 + x);
        SDL_RenderDrawPoint(renderer,x0 - x, y0 + y);
        SDL_RenderDrawPoint(renderer,x0 - x, y0 - y);
        SDL_RenderDrawPoint(renderer,x0 - y, y0 - x);
        SDL_RenderDrawPoint(renderer,x0 + y, y0 - x);
        SDL_RenderDrawPoint(renderer,x0 + x, y0 - y);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}
void Grid::brute_force_particle_collision(){
    for(size_t i = 0; i < particles.size() - 1; i++){
        Particle& p1  = particles[i];
        for(size_t j = i+1; j < particles.size(); j++){
            Particle& p2 = particles[j];

            if(p1.check_part_collision(p2)){
                p1.collide(p2);
            }
        }
    }
}
void Grid:: update(SDL_Renderer* renderer, uint64_t tick, uint64_t prev_tick){
    float delta =  (tick - prev_tick)/1000.0f;
    

    brute_force_particle_collision();
    for(Particle& p : particles){
        p.speed_update(delta);
        p.bounce_wall_x();
        p.bounce_wall_y();
        draw_circle(p, renderer);

    }

}
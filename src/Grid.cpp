#include "Particle.h"
#include <iostream>
#include "constants.h"
#include "Cell.h"
#include "Grid.h"
#include <random>

Grid::Grid(std::vector<Cell> cells, std::vector<Particle> particles){
    set_cells(cells);
    set_particle_init_rand(particles);
}
void Grid::set_cells(std::vector<Cell> new_cells){
    cells = new_cells;
}
void Grid:: set_particle_init_rand(std::vector<Particle> new_p){
        // make random particle list
    std::cout << "Reached";
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
    for(int i = 0; i < 1; i++){
        random_num_x = distr(gen);
        random_num_y = distr(gen);
        rand_x = distr_X(gen);
        rand_y = distr_Y(gen);
        new_p.emplace_back(rand_x, rand_y, radius, random_num_x, random_num_y);
    }
    particles = new_p;
}
void Grid::draw_circle(Particle p, SDL_Renderer* renderer ){
    int y0 = p.get_pos_y();
    int x0 = p.get_pos_x();
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
void Grid:: update(SDL_Renderer* renderer, uint64_t tick, uint64_t prev_tick){
    uint64_t delta =  tick - prev_tick;
     for(Particle& p : particles){
        p.speed_update(delta);
        if(p.bounce_check_x_wall()){
            p.bounce_x();
        }
        if(p.bounce_check_y_wall()){
            p.bounce_y();
        }
        
        draw_circle(p, renderer);

    }
}
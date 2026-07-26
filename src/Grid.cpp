#include "Particle.h"
#include <iostream>
#include "constants.h"
#include "Cell.h"
#include "Grid.h"
#include <random>
#include <chrono>
#include <map>
#include <cmath>
//edit map to be unordred map instead and make custom hash function
Grid::Grid(std::map<std::pair<int, int>, Cell> cells, std::vector<Particle> particles, int num_particles){
    set_particle_init_rand(particles, num_particles);
    //custom_particle_init(particles);
    set_cells_init(cells);
}
void Grid::set_cells_init(std::map<std::pair<int, int>, Cell> new_cells){

    int next_cell = 0;
    int cell_end = Consts::HEIGHT - next_cell;
    while(next_cell + (Consts::SIDE_LENGTH) <= cell_end){
        int y_start = 0;
        while(y_start + (Consts::SIDE_LENGTH) <= cell_end){
            std::pair<int, int> new_coords = {next_cell, y_start};
            Cell new_cell(Consts::SIDE_LENGTH, new_coords, {}, {});
            new_cells.insert({new_coords, new_cell});
            y_start += Consts::SIDE_LENGTH;
        }
        next_cell += Consts::SIDE_LENGTH;
 
        
    }

    std::vector<std::pair<int, int>>  new_neighbors;
    for (auto& [coords, cell] : new_cells) {
        //right neighbor
        if(coords.first + (Consts::SIDE_LENGTH*2)  <=cell_end){
            new_neighbors.emplace_back(coords.first + Consts::SIDE_LENGTH, coords.second);
        }
        if(coords.second + (Consts::SIDE_LENGTH*2)  <= cell_end){
            new_neighbors.emplace_back(coords.first, coords.second + Consts::SIDE_LENGTH);
        }
        if(coords.second + (Consts::SIDE_LENGTH*2)  <=cell_end && coords.first - Consts::SIDE_LENGTH >= 0){
            new_neighbors.emplace_back(coords.first - Consts::SIDE_LENGTH, coords.second + Consts::SIDE_LENGTH);
        }
        if(coords.first + (Consts::SIDE_LENGTH*2)  <=cell_end && coords.second + (Consts::SIDE_LENGTH*2)){
            new_neighbors.emplace_back(coords.first + Consts::SIDE_LENGTH, coords.second + Consts::SIDE_LENGTH);
        }
        cell.set_cell_neighbors(new_neighbors);
    }
    cells = new_cells;


    /*
    int side_length, std::pair<int, int> cell_coords, std::vector<size_t> particles, std::vector<std::pair<int, int>> neighbors
    Plan for init cells:
    1. create hash map (for grid's cells object) key = coords to a cell's top left corner. value = cell object
    2. each cell object will be initialized with an empty neighbor and particle list
    3. we pass over each key in the hash map and for each cell we assign neihgbors based on top left corner => 
    cell1 + 2*radius = right neighbor starting point. for cell neighbors we store the KEY not the cell objects themselves
    similarily we iterate over the particle vector and give references to the particles for the cell to manipulate
    
    
    */

}
int Grid::get_cell_length(){
    return cell_length;
}
std::pair<int, int> Grid::get_closest_cell(std::pair<int, int> part_coords){
    int x = ((part_coords.first / get_cell_length()) * get_cell_length());
    int y = ((part_coords.second / get_cell_length()) * get_cell_length());
    return {x, y};
}
void Grid::populate_cells(){
    for(std::size_t i = 0; i < particles.size() ; i++){
       std::pair<int, int> part_coords = particles[i].get_int_coords();

       std::pair<int, int> cell_coords = get_closest_cell(part_coords);
       if(cells.count(cell_coords) > 0){
               cells.at(cell_coords).add_particle(i); // cell object, add particle index to the particle list

       }

    }


}
void Grid::cell_collision(){
    for (auto& [coords, cell] : cells) {
        //does not do neighboring cells yet => can just get particle list for neighboring cells and run the same check

        std::vector<size_t> particle_list = cell.get_particles();
        if(particle_list.size() > 1){
            for(size_t i = 0; i < particle_list.size() - 1; i++){
                Particle &p1 = particles.at(particle_list.at(i));
                for(size_t j = i + 1; j < particle_list.size(); j++){

                    Particle &p2 = particles.at(particle_list.at(j));
                    if(p1.check_part_collision(p2)){
                        p1.collide(p2);
                    }else{

                    }
                }
            }
            
        }
        cell.set_particles({});
    }

    
    
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
    new_p.emplace_back(0, 0, 10, 0.0f, 0);

   // new_p.emplace_back(101, 101, 10, -100.0f, 0);

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
/*
void Grid:: refresh_cells(){

}
*/
void Grid::cell_sweep_collision(){
    populate_cells();
    cell_collision();

}
void Grid:: update(SDL_Renderer* renderer, uint64_t tick, uint64_t prev_tick){
    float delta =  (tick - prev_tick)/1000.0f;
    
    auto start = std::chrono::high_resolution_clock::now();
    cell_sweep_collision(); //still need to add neighbor check
    //brute_force_particle_collision();
    //refresh_cells();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << elapsed.count() << " microseconds\n";
    for(Particle& p : particles){
        p.speed_update(delta);
        p.bounce_wall_x();
        p.bounce_wall_y();
        draw_circle(p, renderer);

    }

}
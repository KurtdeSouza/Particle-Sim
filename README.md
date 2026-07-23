# Project Summary:
A particle simulator currently with basic functionality like window rendering and pixel drawing built in WSL

## Dependencies:
- WSL (OS)
- g++
- SDL2
- C++17

### If you're on Windows without WSL set up:
1. `wsl --install`
2. `sudo apt update && sudo apt upgrade -y`
3. `sudo apt install build-essential -y`
## Setup:
0. `git clone https://github.com/KurtdeSouza/Particle-Sim.git`
1. `sudo apt install libsdl2-dev -y`
## Running:
1. `make`
2. `./sim`

## Road Map:
- add multiple particle rendering
- implement multithreading to improve render time
- implement custom pool allocator for faster memory allocation
- implement benchmarking to capture render time and other resource use
- implement new forces (gravity, friction, magnetic etc...)

## Rough Metrics:
### Brute Force Collision Calculation:
we check every pair of particles so cost is:
(n(n-1))/2 ~ n^2
| Particles | Pairs checked | Time (μs) | Time per pair (μs) |
|-----------|---------------|-----------|---------------------|
| 1         | 0             | 0.3       | —                   |
| 10        | 45            | 25        | 0.556               |
| 100       | 4,950         | 300       | 0.061               |
| 500       | 124,750       | 7,500     | 0.060               |
| 1000      | 499,500       | 25,575    | 0.051               |
| 2000      | 1,999,000     | 100,312   | 0.050               |

# TODO:
- need to fix how I init grid, cells, and particles
- maybe re organize render cpp to make more sense and be cleaner
- need to init cell class to house the particle list before rendering starts then call update and cell iteration per frame

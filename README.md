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

### spatial partitioning (Uniform Grid) Calculation (std::Map cells):
roughly O(n(log(c))) if particles are evenly distributed across the grid where n = number of particles, c = number of cells.
if concentrated into a few cells then complexity moves to roughly O(n^2)
| Particles |Time (μs) | 
|-----------|----------|
| 1         | 700      | 
| 10        | 700      |
| 100       | 900      |
| 500       | 2300     |
| 1000      | 3422     |
| 2000      | 8739     |

### spatial partitioning (Uniform Grid) Calculation (std::unordered_map cells + (custom hash) hashed coordinate system):
roughly O(n) if particles are evenly distributed across the grid where n = number of particles.
if concentrated into a few cells then complexity moves to roughly O(n^2)
| Particles |Time (μs) | 
|-----------|----------|
| 1         | 600      | 
| 10        | 650      |
| 100       | 675      |
| 500       | 1700     |
| 1000      | 2342     |
| 2000      | 5000     |
# TODO:


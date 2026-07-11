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
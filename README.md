A terminal 2D physics engine written in C++. Creates a scene with objects defined by convex polygons, simulates rigid body dynamics (forces, torques, velocity, angular velocity), and renders the result to the terminal using ncurses. A keyboard-controlled game loop lets the user apply forces and rotation to objects in real time.
## Stack
- Language: C++
- Build: CMake
- Libraries: Standard Library, ncurses, Google Test
## How to Run
```bash
git clone https://github.com/neburion/term-phys.git
make release
./bin/term-phys
```

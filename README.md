<div align="center">
  <img height="128" width="128" src="https://github.com/user-attachments/assets/ecc23eb7-63d1-4dca-b4ae-922dfa8f33e1">
  <h1>cub3d</h1>
</div>

This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.

## About the project
This project is part of the 42 curriculum and focuses on creating a 3D maze game using raycasting techniques. The main objectives include:
- Implementing a raycasting engine from scratch
- Creating a first-person perspective view
- Handling player movement and rotation
- Managing textures for walls
- Processing keyboard inputs for smooth controls
- Understanding 3D graphics fundamentals

### Key Requirements
- The game must use raycasting for 3D rendering
- Player must be able to move through the maze with WASD keys
- Player must be able to rotate the camera with arrow keys
- Configuration file must specify:
  - `NO`/`SO`/`WE`/`EA` Texture for walls
  - `F`/`C` Floor and ceiling colors
- Map must be constructed with these components:
  - `1` Walls
  - `0` Empty spaces
  - `N`/`S`/`E`/`W` Player starting position and orientation

### Bonus features
- Wall collisions
- Minimap system
- Doors that can open and close (`D` in map)
- Animated sprites (`Tab` separated)
- Mouse rotation

### Skills Learned
- 3D graphics programming fundamentals
- Raycasting implementation
- Texture mapping and rendering
- Mathematical concepts for graphics
- Optimization techniques for real-time rendering
- Event handling in a graphical environment

## Getting started
### Requirements
**For Linux**
```bash
sudo apt-get install gcc libbsd-dev libxext-dev make xorg
```

**For macOS**
```bash
brew install xquartz
reboot
```

### Build and run
```bash
make
./cub3d_bonus assets/maps/mc_subject_bonus.cub
```
*You can replace `assets/maps/mc_subject_bonus.cub` by any `.cub` file.*

## Credits
<img align="right" src="https://github.com/user-attachments/assets/099e6b70-35e1-49e3-9ac4-dc3194232eb8">

- [42](https://42.fr/)
- [MinilibX](https://github.com/42Paris/minilibx-linux)
- [42 Docs - MinilibX](https://harm-smits.github.io/42docs/libs/minilibx)

```c
cub->map[y][x];
cub->map[0][0]; // top left corner
cub->map[69][420]; // bottom right corner

double dir_x = cos(cub->dir);
double dir_y = sin(cub->dir);

// facing to North
cub->dir = -M_PI_2;
dir_x = 0;
dir_y = -1;
// facing to South
cub->dir = M_PI_2;
dir_x = 0;
dir_y = 1;
// facing to West
cub->dir = M_PI;
dir_x = -1;
dir_y = 0;
// facing to East
cub->dir = 0;
dir_x = 1;
dir_y = 0;

cub->dir += M_PI_2; // Rotate 90 degree clockwise/right
cub->dir -= M_PI_2; // Rotate 90 degree counter clockwise/left
```


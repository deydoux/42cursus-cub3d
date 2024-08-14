```c
cub->map[y][x];
cub->map[0][0]; // top left corner
cub->map[69][420]; // bottom right corner

dir_x = sin(cub->dir);
dir_y = cos(cub->dir);
// facing to North
cub->dir = M_PI;
dir_x = 0;
dir_y = -1;
// facing to South
cub->dir = 0;
dir_x = 0;
dir_y = 1;
// facing to West
cub->dir = -M_PI_2;
dir_x = -1;
dir_y = 0;
// facing to East
cub->dir = M_PI_2;
dir_x = 1;
dir_y = 0;
```


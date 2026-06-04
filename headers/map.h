#pragma once

//color for the celling and the floor
typedef struct color
{
    int red;
    int green;
    int blue;
};

//struct wich contains the infos of map
typedef struct map
{
    char    **map;
    int     length;
    int     width;
    color   *fc;
};

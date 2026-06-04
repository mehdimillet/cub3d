#pragma once

typedef enum t_check;

//color for the celling and the floor
typedef struct s_color
{
    int red;
    int green;
    int blue;
}t_color;

typedef struct s_texture
{
    
}t_texture;


//struct wich contains the infos of map
typedef struct s_cub
{
    int         length;
    int         width;
    char        **map;
    t_check     nodouble;
    t_color     floor;
    t_color     ceiling;
    t_player    pos;
}t_cub;

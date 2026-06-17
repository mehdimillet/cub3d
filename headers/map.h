#ifndef MAP_H
# define MAP_H

//color for the celling and the floor
typedef struct s_color
{
	int red;
	int green;
	int blue;
}t_color;

typedef struct s_texture
{
	char	*path;
	void	*img;
	int		length;
	int		width;
}t_texture;


//struct wich contains the infos of map
//tex[0] NO / tex[1] SO / tex[2] WE/ tex[3] EA
typedef struct s_cub
{
	char		**map;
	int			height; //j'ai ajoute ca j'en ai besoin pour le raycasting
	int			width; //
	int			seen[6];
	t_color		floor;
	t_color		ceiling;
	t_player	pos;
	t_texture	tex[4];
}t_cub;

#endif
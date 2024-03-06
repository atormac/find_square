#ifndef MAP_H
# define MAP_H

typedef struct t_map
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
	char	*map_buf;
}	t_map;

typedef struct t_square
{
	int	find_length;
	int	find_height;
	int	find_width;
	int	size;
	int	x;
	int	y;
}	t_square;
#endif

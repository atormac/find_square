
#include <unistd.h>
#include "map.h"

void	print_str(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_map(int **matrix, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (matrix[x][y] == 0)
				print_char(map->empty);
			else if (matrix[x][y] == 1)
				print_char(map->full);
			else if (matrix[x][y] == 2)
				print_char(map->obstacle);
			y++;
		}
		print_char('\n');
		x++;
	}
}

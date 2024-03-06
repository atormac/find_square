#include "map.h"
#include <stdlib.h>

int	is_square(int **matrix, struct t_map *map, struct t_square *square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (square->find_length > map->width - square->find_width)
		return (0);
	if (square->find_length > map->height - square->find_height)
		return (0);
	while (i < square->find_length)
	{
		j = 0;
		while (j < square->find_length)
		{
			if (matrix[square->find_height + i][square->find_width + j] == 2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	find_largest(int **matrix, struct t_map *map,
						struct t_square *square, int max_length)
{
	while (square->find_length <= max_length)
	{
		if (is_square(matrix, map, square) == 0)
			break ;
		if (square->find_length > square->size)
		{
			square->size = square->find_length;
			square->y = square->find_height;
			square->x = square->find_width;
		}
		square->find_length++;
	}
}

void	find_square(int **matrix, struct t_map *map, struct t_square *square)
{
	int	max_length;

	max_length = map->width;
	if (map->height < map->width)
		max_length = map->height;
	while (square->find_height < map->height)
	{
		square->find_width = 0;
		while (square->find_width < map->width)
		{
			if (matrix[square->find_height][square->find_width] != 2)
			{
				find_largest(matrix, map, square, max_length);
			}
			square->find_width++;
		}
		square->find_height++;
	}
}

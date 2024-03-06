#include <stdlib.h>
#include "map.h"

int		ft_strlen(char *str);
int		ft_atoi(char *str, int limit);
int		num_len(char *str);
char	*line_next(char *map_str);
int		line_length(char *map_str);
int		line_is_printable(char *s);
int		line_map_width(char *map_str);

int	map_check(struct t_map *map, char *map_str)
{
	int	height;
	int	width;

	height = 0;
	map_str = line_next(map_str);
	while (*map_str && height < map->height)
	{
		width = 0;
		if (!line_is_printable(map_str))
			return (0);
		if (line_length(map_str) != map->width)
			return (0);
		while (width < map->width)
		{
			if (map_str[width] != map->obstacle && map_str[width] != map->empty)
				return (0);
			width++;
		}
		map_str = line_next(map_str);
		height++;
	}
	if (height != map->height)
		return (0);
	return (1);
}

int	map_valid(struct t_map *map)
{
	if (map->width <= 0 || map->height <= 0)
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full)
		return (0);
	if (map->obstacle == map->full)
		return (0);
	if (!map_check(map, map->map_buf))
		return (0);
	return (1);
}

struct t_map	*map_parse(char *map_str)
{
	t_map	*map;
	int		flen;

	if (ft_strlen(map_str) < 5 || !line_is_printable(map_str))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	flen = line_length(map_str);
	map->map_buf = map_str;
	map->height = ft_atoi(map_str, flen - 3);
	map->width = line_map_width(map_str);
	map->empty = map_str[flen - 3];
	map->obstacle = map_str[flen - 2];
	map->full = map_str[flen - 1];
	if (!map_valid(map))
	{
		free(map);
		return (NULL);
	}
	return (map);
}

void	map_init(int **matrix, struct t_map *map)
{
	int		height;
	int		width;
	char	*map_str;

	height = 0;
	map_str = line_next(map->map_buf);
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (map_str[width] == map->obstacle)
				matrix[height][width] = 2;
			else if (map_str[width] == map->full)
				matrix[height][width] = 1;
			else if (map_str[width] == map->empty)
				matrix[height][width] = 0;
			width++;
		}
		map_str = line_next(map_str);
		height++;
	}
}

void	map_fill(int **matrix, struct t_square *square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (square->size == 0)
		return ;
	while (i < square->size)
	{
		j = 0;
		while (j < square->size)
		{
			matrix[square->y + i][square->x + j] = 1;
			j++;
		}
		i++;
	}
}

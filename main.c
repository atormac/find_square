#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "map.h"

int				**matrix_allocate(int width, int height);
void			matrix_free(int **matrix, int height);
void			print_str(char *str);
void			print_char(char c);
char			*read_file(int fd, int buf_size, int *out_size);
struct t_map	*map_parse(char *map);
void			map_init(int **matrix, struct t_map *map);
void			find_square(int **matrix,
					struct t_map *map, struct t_square *square);
void			map_fill(int **matrix, struct t_square *square);
void			print_map(int **matrix, t_map *map);
struct t_square	*square_init(void);

int	find_solution(t_map *map)
{
	t_square	*square;
	int			**matrix;

	matrix = matrix_allocate(map->width, map->height);
	if (!matrix)
	{
		free(map);
		return (0);
	}
	map_init(matrix, map);
	square = square_init();
	if (!square)
	{
		free(matrix);
		free(map);
		return (0);
	}
	find_square(matrix, map, square);
	map_fill(matrix, square);
	print_map(matrix, map);
	matrix_free(matrix, map->height);
	free(square);
	return (1);
}

struct t_map	*load_map_file(char *path)
{
	t_map	*map;
	char	*map_buf;
	int		map_buf_size;
	int		fd;

	fd = open(path, O_RDONLY);
	map_buf = read_file(fd, 1024, &map_buf_size);
	close(fd);
	if (!map_buf)
		return (0);
	map = map_parse(map_buf);
	if (!map)
	{
		free(map_buf);
		return (0);
	}
	return (map);
}

void	load_stdin(void)
{
	t_map	*map;
	int		map_buf_size;
	char	*map_buf;

	map_buf_size = 0;
	map_buf = read_file(0, 1024, &map_buf_size);
	if (!map_buf)
		return ;
	map = map_parse(map_buf);
	if (!map)
	{
		print_str("map error\n");
		free(map_buf);
		return ;
	}
	find_solution(map);
	free(map->map_buf);
	free(map);
}

void	handle_args(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	while (i < argc)
	{
		map = load_map_file(argv[i]);
		if (!map)
		{
			print_str("map error\n");
			i++;
			continue ;
		}
		find_solution(map);
		free(map->map_buf);
		free(map);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		handle_args(argc, argv);
		return (0);
	}
	load_stdin();
	return (0);
}

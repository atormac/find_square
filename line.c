#include <stdlib.h>

char	*line_next(char *map_str)
{
	while (*map_str && *map_str != '\n')
		map_str++;
	if (*map_str)
	    map_str++;
	return (map_str);
}

int	line_length(char *map_str)
{
	char	*line_start;

	line_start = map_str;
	while (*map_str && *map_str != '\n')
		map_str++;
	return (map_str - line_start);
}

int	line_map_width(char *map_str)
{
	while (*map_str)
	{
		if (*map_str == '\n')
		{
			map_str++;
			return (line_length(map_str));
		}
		map_str++;
	}
	return (0);
}

int	line_is_printable(char *s)
{
	while (*s && *s != '\n')
	{
		if (!(*s >= 32 && *s <= 126))
			return (0);
		s++;
	}
	return (1);
}

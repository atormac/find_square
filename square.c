
#include "map.h"
#include <stdlib.h>

struct t_square	*square_init(void)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (square == NULL)
		return (NULL);
	square->find_length = 1;
	square->find_height = 0;
	square->find_width = 0;
	square->size = 0;
	square->y = 0;
	square->x = 0;
	return (square);
}


#include <stdlib.h>

void	my_memset(void *dest, int val, int size)
{
	unsigned char	*p;

	p = dest;
	while (size-- > 0)
	{
		*p++ = val;
	}
}

int	**matrix_allocate(int width, int height)
{
	int	i;
	int	**array;

	i = 0;
	array = (int **)malloc(height * sizeof(int *));
	if (!array)
		return (NULL);
	my_memset(array, 0, height * sizeof(int *));
	while (i < height)
	{
		array[i] = malloc(width * sizeof(int));
		if (!array[i])
			return (NULL);
		my_memset(array[i], 0, width * sizeof(int));
		i++;
	}
	return (array);
}

void	matrix_free(int **matrix, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

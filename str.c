
#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

int	ft_atoi(char *str, int limit)
{
	int	ret;

	ret = 0;
	while (*str && *str >= '0' && *str <= '9' && limit > 0)
	{
		ret = ret * 10 + *str - '0';
		str++;
		limit--;
	}
	return (ret);
}

int	num_len(char *str)
{
	char	*s;

	s = str;
	while (*str && *str >= '0' && *str <= '9')
	{
		str++;
	}
	return (str - s);
}

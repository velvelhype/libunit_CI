#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

static int	success(void)
{
	char	str[32];

	sprintf(str, "%d", INT_MIN);
	return (ft_atoi(str) == atoi(str));
}

int	ft_atoi_int_mini_test(void)
{
	if (success())
		return (0);
	else
		return (-1);
}

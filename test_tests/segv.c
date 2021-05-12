#include <stdio.h>

int	segv(void)
{
	char *ptr;

	ptr = NULL;
	*ptr = 0;
	return (0);
}

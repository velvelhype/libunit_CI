#include <stdlib.h>
int	ft_strlen_launcher(void);
int	ft_atoi_launcher(void);

int	main(void)
{
	ft_strlen_launcher();
	ft_atoi_launcher();
	chat *imp;
	imp = (char*)malloc(100);
	system("leaks a.out");
	return (0);
}

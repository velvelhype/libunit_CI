#include <stdio.h>
#include "libunit.h"
#include <unistd.h>

int	basic_test(void);
int	null_test(void);
int	bus_error(void);
int	segv(void);

int strlen_launcher(void)
{
    t_unit_tests unit_tests;

	write(1,"STRLEN:",8);
	init_tests(&unit_tests);
	load_test(&unit_tests, "Basic test", &basic_test);
	load_test(&unit_tests, "NULL test", &null_test);
	load_test(&unit_tests, "Bus error test", &bus_error);
	load_test(&unit_tests, "Segmentaion fault test", &segv);

	return(launch_tests(&unit_tests));
}

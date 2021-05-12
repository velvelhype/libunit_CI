/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:15:24 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/10 19:27:46 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "private.h"

void	print_result(t_unit_tests *unit_tests, t_unit_test *test)
{
	int	stat_loc;

	wait(&stat_loc);
	if (WIFSIGNALED(stat_loc))
	{
		if (WTERMSIG(stat_loc) == SIGSEGV)
			printf("\t%-30s : [SIGV]\n", test->test_name);
		if (WTERMSIG(stat_loc) == SIGBUS)
			printf("\t%-30s : [BUSE]\n", test->test_name);
	}
	else if (WIFEXITED(stat_loc))
	{
		if (WEXITSTATUS(stat_loc) == 0)
		{
			printf("\t%-30s : [OK]\n", test->test_name);
			unit_tests->success++;
		}
		else if (WEXITSTATUS(stat_loc) == (-1 & 0xff))
		{
			printf("\t%-30s : [KO]\n", test->test_name);
		}
	}
	unit_tests->total++;
}

int fork_place(t_unit_tests *unit_tests, t_unit_test	*test)
{
		pid_t	pid = fork();

		int result;
		if (pid == -1)
			return (ERROR);
		if (pid == 0)
		{
			result = test->test_func();
			free_tests(unit_tests);
			exit(result);
			//_exit(result);

		}
		//exit(result);
		print_result(unit_tests, test);

		return 0;
}

int	launch_tests(t_unit_tests *unit_tests)
{
	t_unit_test	*test;
	int result;
	test = unit_tests->head;
	while (test)
	{
		result = fork_place(unit_tests, test);
				test = test->next;
	}
	printf("%d / %d tests checked\n", unit_tests->success, unit_tests->total);
	if (unit_tests->success == unit_tests->total)
		return (0);
	else
		return (-1);
}

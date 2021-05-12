/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:16:52 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/10 17:08:28 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "libunit.h"

# define TRUE	1
# define FALSE	0
# define OK		1
# define ERROR	-1

t_unit_test	*new_test(const char *test_name, int (*test_func)(void));
void		add_test(t_unit_tests *list, t_unit_test *test);
char		*ft_strdup(const char *str);

#endif

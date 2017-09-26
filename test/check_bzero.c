/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 21:16:59 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>

char	*g_test_name = "ft_bzero";

static void	check_bzero_simple(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_bzero(s1, 7);
	   bzero(s2, 7);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_bzero_one(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_bzero(s1, 1);
	   bzero(s2, 1);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_bzero_zero(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_bzero(s1, 0);
	   bzero(s2, 0);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_bzero_middle(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_bzero(s1 + 5, 20);
	   bzero(s2 + 5, 20);
	assert(memcmp(s1, s2, 32), 0);
}

void 	(*check_functions[]) =
{
	check_bzero_simple,
	check_bzero_one,
	check_bzero_zero,
	check_bzero_middle,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

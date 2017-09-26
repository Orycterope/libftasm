/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 21:17:12 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>

char	*g_test_name = "ft_memset";

static void	check_memset_simple(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_memset(s1, 'x', 7);
	   memset(s2, 'x', 7);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memset_one(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_memset(s1, '#', 1);
	   memset(s2, '#', 1);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memset_zero(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_memset(s1, 'x', 0);
	   memset(s2, 'x', 0);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memset_middle(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_memset(s1 + 5, '#', 20);
	   memset(s2 + 5, '#', 20);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memset_overflow(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	ft_memset(s1 + 5, 0xabcdef, 20);
	   memset(s2 + 5, 0xabcdef, 20);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memset_return (void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };
	char	*ret1;
	char	*ret2;

	ret1 = ft_memset(s1 + 5, '#', 20);
	ret2 =    memset(s2 + 5, '#', 20);
	assert(ret1, ret2 - (s2 - s1));
}

void 	(*check_functions[]) =
{
	check_memset_simple,
	check_memset_one,
	check_memset_zero,
	check_memset_middle,
	check_memset_overflow,
	check_memset_return,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

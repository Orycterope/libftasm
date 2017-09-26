/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/21 12:03:50 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>

char	*g_test_name = "ft_memcpy";

static void	check_memcpy_simple(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };
	char	src[32];
	int		i;

	i = -1;
	while (++i < 32)
		src[i] = i;
	ft_memcpy(s1, src + 5, 7);
	   memcpy(s2, src + 5, 7);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memcpy_one(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };
	char	src[32];
	int		i;

	i = -1;
	while (++i < 32)
		src[i] = i;
	ft_memcpy(s1, src + 5, 1);
	   memcpy(s2, src + 5, 1);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memcpy_zero(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };
	char	src[32];
	int		i;

	i = -1;
	while (++i < 32)
		src[i] = i;
	ft_memcpy(s1, src + 5, 0);
	   memcpy(s2, src + 5, 0);
	assert(memcmp(s1, s2, 32), 0);
}

static void	check_memcpy_src_unchanged(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };
	char	src2[32];
	char	src1[32];
	int		i;

	i = -1;
	while (++i < 32)
	{
		src1[i] = i;
		src2[i] = i;
	}
	ft_memcpy(s1, src1 + 5, 0);
	   memcpy(s2, src2 + 5, 0);
	assert(memcmp(src1, src2, 32), 0);
}

static void	check_memcpy_overlap_one(void)
{
	char	src1[32];
	char	src2[32];
	int		i;

	i = -1;
	while (++i < 32)
	{
		src1[i] = i;
		src2[i] = i;
	}
	ft_memcpy(src1 + 5, src1 + 8, 20);
	   memcpy(src2 + 5, src2 + 8, 20);
	test(memcmp(src1, src2, 32), 0);
}

static void	check_memcpy_overlap_two(void)
{
	char	src1[32];
	char	src2[32];
	int		i;

	i = -1;
	while (++i < 32)
	{
		src1[i] = i;
		src2[i] = i;
	}
	ft_memcpy(src1 + 8, src1 + 5, 20);
	   memcpy(src2 + 8, src2 + 5, 20);
	test(memcmp(src1, src2, 32), 0);
}

static void	check_memcpy_return (void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };
	char	src[32];
	int		i;
	char	*ret1;
	char	*ret2;

	i = -1;
	while (++i < 32)
		src[i] = i;
	ret1 = ft_memcpy(s1, src + 5, 20);
	ret2 =    memcpy(s2, src + 5, 20);
	assert(ret1, ret2 - (s2 - s1));
}

void 	(*check_functions[]) =
{
	check_memcpy_simple,
	check_memcpy_one,
	check_memcpy_zero,
	check_memcpy_src_unchanged,
	check_memcpy_overlap_one,
	check_memcpy_overlap_two,
	check_memcpy_return,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

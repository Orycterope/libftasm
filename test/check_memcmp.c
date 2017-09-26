/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:56:39 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 15:10:54 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

char	*g_test_name = "ft_memcmp";

static void	check_memcmp_diff_simple(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Hello World!", "Hello Wxrld!", 12);
	ret2 =    memcmp("Hello World!", "Hello Wxrld!", 12);
	assert(ret1, ret2);
}

static void	check_memcmp_same_simple(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Hello World!", "Hello World!", 12);
	ret2 =    memcmp("Hello World!", "Hello World!", 12);
	assert(ret1, ret2);
}

static void	check_memcmp_end_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Hello World!", "Hello World!", 4);
	ret2 =    memcmp("Hello World!", "Hello World!", 4);
	assert(ret1, ret2);
}

static void	check_memcmp_end_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Helxo World!", "Hello World!", 4);
	ret2 =    memcmp("Helxo World!", "Hello World!", 4);
	assert(ret1, ret2);
}

static void	check_memcmp_post_end_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Hellx World!", "Hello World!", 4);
	ret2 =    memcmp("Hellx World!", "Hello World!", 4);
	assert(ret1, ret2);
}

static void	check_memcmp_one_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Hello World!", "Hello World!", 1);
	ret2 =    memcmp("Hello World!", "Hello World!", 1);
	assert(ret1, ret2);
}

static void	check_memcmp_one_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("xello World!", "Hello World!", 1);
	ret2 =    memcmp("xello World!", "Hello World!", 1);
	assert(ret1, ret2);
}

static void	check_memcmp_zero_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("Hello World!", "Hello World!", 0);
	ret2 =    memcmp("Hello World!", "Hello World!", 0);
	assert(ret1, ret2);
}

static void	check_memcmp_zero_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_memcmp("xello World!", "Hello World!", 0);
	ret2 =    memcmp("xello World!", "Hello World!", 0);
	assert(ret1, ret2);
}

static void	check_memcmp_neg_diff(void)
{
	int	ret1;
	int	ret2;
	char	src[12] = {'H','e','l','l','o',' ','W',-42,'r','l','d','!'};

	ret1 = ft_memcmp("Hello World!", src, 12);
	ret2 =    memcmp("Hello World!", src, 12);
	assert(ret1, ret2);
}

static void	check_memcmp_big(void)
{
	int		ret1;
	int		ret2;
	char	src[4096] = { [0 ... 4094] = 1, [4095] = 0 };

	ret1 = ft_memcmp(src, src, 4096);
	ret2 =    memcmp(src, src, 4096);
	assert(ret1, ret2);
}

void 	(*check_functions[]) =
{
	check_memcmp_diff_simple,
	check_memcmp_same_simple,
	check_memcmp_end_same,
	check_memcmp_end_diff,
	check_memcmp_post_end_diff,
	check_memcmp_one_same,
	check_memcmp_one_diff,
	check_memcmp_zero_same,
	check_memcmp_zero_diff,
	check_memcmp_neg_diff,
	check_memcmp_big,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

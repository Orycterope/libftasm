/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:56:39 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 15:59:08 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

char	*g_test_name = "ft_strncmp";

static void	check_strncmp_diff_simple(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hello World!", "Hello Wxrld!", 12);
	ret2 =    strncmp("Hello World!", "Hello Wxrld!", 12);
	assert(ret1, ret2);
}

static void	check_strncmp_same_simple(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hello World!", "Hello World!", 12);
	ret2 =    strncmp("Hello World!", "Hello World!", 12);
	assert(ret1, ret2);
}

static void	check_strncmp_end_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hello World!", "Hello World!", 4);
	ret2 =    strncmp("Hello World!", "Hello World!", 4);
	assert(ret1, ret2);
}

static void	check_strncmp_end_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Helxo World!", "Hello World!", 4);
	ret2 =    strncmp("Helxo World!", "Hello World!", 4);
	assert(ret1, ret2);
}

static void	check_strncmp_post_end_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hellx World!", "Hello World!", 4);
	ret2 =    strncmp("Hellx World!", "Hello World!", 4);
	assert(ret1, ret2);
}

static void	check_strncmp_post_nul_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hel\0x World!", "Hel\0o World!", 12);
	ret2 =    strncmp("Hel\0x World!", "Hel\0o World!", 12);
	assert(ret1, ret2);
}

static void	check_strncmp_one_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hello World!", "Hello World!", 1);
	ret2 =    strncmp("Hello World!", "Hello World!", 1);
	assert(ret1, ret2);
}

static void	check_strncmp_one_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("xello World!", "Hello World!", 1);
	ret2 =    strncmp("xello World!", "Hello World!", 1);
	assert(ret1, ret2);
}

static void	check_strncmp_zero_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("Hello World!", "Hello World!", 0);
	ret2 =    strncmp("Hello World!", "Hello World!", 0);
	assert(ret1, ret2);
}

static void	check_strncmp_zero_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strncmp("xello World!", "Hello World!", 0);
	ret2 =    strncmp("xello World!", "Hello World!", 0);
	assert(ret1, ret2);
}

static void	check_strncmp_neg_diff(void)
{
	int	ret1;
	int	ret2;
	char	src[12] = {'H','e','l','l','o',' ','W',-42,'r','l','d','!'};

	ret1 = ft_strncmp("Hello World!", src, 12);
	ret2 =    strncmp("Hello World!", src, 12);
	assert(ret1, ret2);
}

static void	check_strncmp_big(void)
{
	int		ret1;
	int		ret2;
	char	src[4096] = { [0 ... 4094] = 1, [4095] = 0 };

	ret1 = ft_strncmp(src, src, 4096);
	ret2 =    strncmp(src, src, 4096);
	assert(ret1, ret2);
}

void 	(*check_functions[]) =
{
	check_strncmp_diff_simple,
	check_strncmp_same_simple,
	check_strncmp_end_same,
	check_strncmp_end_diff,
	check_strncmp_post_end_diff,
	check_strncmp_post_nul_diff,
	check_strncmp_one_same,
	check_strncmp_one_diff,
	check_strncmp_zero_same,
	check_strncmp_zero_diff,
	check_strncmp_neg_diff,
	check_strncmp_big,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

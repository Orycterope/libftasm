/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:56:39 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 16:07:19 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

char	*g_test_name = "ft_strcmp";

static void	check_strcmp_diff_simple(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("Hello World!", "Hello Wxrld!");
	ret2 =    strcmp("Hello World!", "Hello Wxrld!");
	assert(ret1, ret2);
}

static void	check_strcmp_same_simple(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("Hello World!", "Hello World!");
	ret2 =    strcmp("Hello World!", "Hello World!");
	assert(ret1, ret2);
}

static void	check_strcmp_longer(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("Hello World!", "Hello");
	ret2 =    strcmp("Hello World!", "Hello");
	assert(ret1, ret2);
}

static void	check_strcmp_post_nul_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("Hel\0x World!", "Hel\0o World!");
	ret2 =    strcmp("Hel\0x World!", "Hel\0o World!");
	assert(ret1, ret2);
}

static void	check_strcmp_one_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("H", "H");
	ret2 =    strcmp("H", "H");
	assert(ret1, ret2);
}

static void	check_strcmp_one_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("x", "H");
	ret2 =    strcmp("x", "H");
	assert(ret1, ret2);
}

static void	check_strcmp_zero_same(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("", "");
	ret2 =    strcmp("", "");
	assert(ret1, ret2);
}

static void	check_strcmp_zero_diff(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp("", "Hello World!");
	ret2 =    strcmp("", "Hello World!");
	assert(ret1, ret2);
}

static void	check_strcmp_neg_diff(void)
{
	int	ret1;
	int	ret2;
	char	src[12] = {'H','e','l','l','o',' ','W',-42,'r','l','d','!'};

	ret1 = ft_strcmp("Hello World!", src);
	ret2 =    strcmp("Hello World!", src);
	assert(ret1, ret2);
}

static void	check_strcmp_big(void)
{
	int		ret1;
	int		ret2;
	char	src[4096] = { [0 ... 4094] = 1, [4095] = 0 };

	ret1 = ft_strcmp(src, src);
	ret2 =    strcmp(src, src);
	assert(ret1, ret2);
}

void 	(*check_functions[]) =
{
	check_strcmp_diff_simple,
	check_strcmp_same_simple,
	check_strcmp_longer,
	check_strcmp_post_nul_diff,
	check_strcmp_one_same,
	check_strcmp_one_diff,
	check_strcmp_zero_same,
	check_strcmp_zero_diff,
	check_strcmp_neg_diff,
	check_strcmp_big,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

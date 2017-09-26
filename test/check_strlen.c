/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/21 13:06:46 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>

char	*g_test_name = "ft_strlen";

static void	check_strlen_hello_world(void)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen("Hello World!");
	len2 =    strlen("Hello World!");
	assert(len1, len2);
}

static void	check_strlen_one(void)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen("X");
	len2 =    strlen("X");
	assert(len1, len2);
}

static void	check_strlen_zero(void)
{
	char	str[32] = { [ 0 ] = 0, [ 1 ... 31 ] = 1 };
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str);
	len2 =    strlen(str);
	assert(len1, len2);
}

static void	check_strlen_long(void)
{
	char	str[4096] = { [ 0 ... 4094 ] = 1, [ 4095 ] = 0 };
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str);
	len2 =    strlen(str);
	assert(len1, len2);
}

static void	check_strlen_no_change(void)
{
	char	str1[32] = { [ 0 ... 30 ] = 7, [ 31 ] = 0 };
	char	str2[32] = { [ 0 ... 30 ] = 7, [ 31 ] = 0 };

	ft_strlen(str1);
	   strlen(str2);
	assert(memcmp(str1, str2, 32), 0);
}

void 	(*check_functions[]) =
{
	check_strlen_hello_world,
	check_strlen_one,
	check_strlen_zero,
	check_strlen_long,
	check_strlen_no_change,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

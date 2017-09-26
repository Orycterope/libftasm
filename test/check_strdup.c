/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:56:39 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/25 15:14:44 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

char	*g_test_name = "ft_strdup";

static void	check_strdup_simple(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("Hello World!");
	s2 =   	strdup("Hello World!");
	assert(strcmp(s1, s2), 0);
	free(s1);
	free(s2);
}

static void	check_strdup_one(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("x");
	s2 =   	strdup("x");
	assert(strcmp(s1, s2), 0);
	free(s1);
	free(s2);
}

static void	check_strdup_zero(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("");
	s2 =   	strdup("");
	assert(strcmp(s1, s2), 0);
	free(s1);
	free(s2);
}

static void	check_strdup_big(void)
{
	char	*s1;
	char	*s2;
	char	src[4096] = { [0 ... 4094] = 1, [4095] = 0 };

	s1 = ft_strdup(src);
	s2 =   	strdup(src);
	assert(strcmp(s1, s2), 0);
	free(s1);
	free(s2);
}

void 	(*check_functions[]) =
{
	check_strdup_simple,
	check_strdup_one,
	check_strdup_zero,
	check_strdup_big,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

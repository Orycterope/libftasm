/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_memalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:56:39 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 14:01:14 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

char	*g_test_name = "ft_memalloc";

static void	check_memalloc_simple(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_memalloc(17);
	s2 =   	  malloc(17);
	bzero(s2, 17);
	assert(memcmp(s1, s2, 17), 0);
	free(s1);
	free(s2);
}

static void	check_memalloc_one(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_memalloc(1);
	s2 =   	  malloc(1);
	bzero(s2, 1);
	assert(memcmp(s1, s2, 1), 0);
	free(s1);
	free(s2);
}

static void	check_memalloc_zero(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_memalloc(0);
	s2 =   	  malloc(0);
	bzero(s2, 0);
	assert(memcmp(s1, s2, 0), 0);
	free(s1);
	free(s2);
}

static void	check_memalloc_big(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_memalloc(8192);
	s2 =   	  malloc(8192);
	bzero(s2, 8192);
	assert(memcmp(s1, s2, 8192), 0);
	free(s1);
	free(s2);
}

void 	(*check_functions[]) =
{
	check_memalloc_simple,
	check_memalloc_one,
	check_memalloc_zero,
	check_memalloc_big,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

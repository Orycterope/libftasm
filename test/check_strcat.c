/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/21 12:22:22 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>

char	*g_test_name = "ft_strcat";

static void	check_strcat_hello_world(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	ft_strcat(s1, "World");
	   strcat(s2, "World");
	assert(strcmp(s1, s2), 0);
}

static void	check_strcat_len(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	ft_strcat(s1, "World");
	   strcat(s2, "World");
	assert(strlen(s1), strlen(s2));
}

static void	check_strcat_end(void)
{
	char	s1[32] = { [0 ... 31] = 1 };
	char	s2[32] = { [0 ... 31] = 1 };

	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	ft_strcat(s1, "World");
	strcat(s2, "World");
	assert(*(s1 + 10), *(s2 + 10));
	assert(*(s1 + 11), *(s2 + 11));
	assert(*(s1 + 12), *(s2 + 12));
	assert(strcmp(s1, s2), 0);
	assert(strlen(s1), strlen(s2));
}

static void	check_strcat_empty_1(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	ft_strcat(s1, "World");
	   strcat(s2, "World");
	assert(strcmp(s1, s2), 0);
	assert(strlen(s1), strlen(s2));
}

static void	check_strcat_empty_2(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	ft_strcat(s1, "");
	   strcat(s2, "");
	assert(strcmp(s1, s2), 0);
	assert(strlen(s1), strlen(s2));
}

static void	check_strcat_empty_both(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	ft_strcat(s1, "");
	   strcat(s2, "");
	assert(strcmp(s1, s2), 0);
	assert(strlen(s1), strlen(s2));
}

static void check_strcat_return (void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };
	char	*ret1;
	char	*ret2;

	ret1 = ft_strcat(s1, "");
	ret2 = 	  strcat(s2, "");
	assert(ret1, ret2 - (s2 - s1));
	ret1 = ft_strcat(s1, "Hello");
	ret2 = 	  strcat(s2, "Hello");
	assert(ret1, ret2 - (s2 - s1));
	ret1 = ft_strcat(s1, "World");
	ret2 = 	  strcat(s2, "World");
	assert(ret1, ret2 - (s2 - s1));
	ret1 = ft_strcat(s1, "");
	ret2 = 	  strcat(s2, "");
	assert(ret1, ret2 - (s2 - s1));
}

/*static void	check_strcat_overlap_easy(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	ft_strcat(s1, s1 + 2);
	   strcat(s2, s2 + 2);
	test(strcmp(s1, s2), 0);
}*/

static void	check_strcat_overlap_hard(void)
{
	char	s1[32] = { 0 };
	char	s2[32] = { 0 };

	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	ft_strcat(s1 + 2, "World");
	   strcat(s2 + 2, "World");
	test(strcmp(s1, s2), 0);
}

void 	(*check_functions[]) =
{
	check_strcat_hello_world,
	check_strcat_len,
	check_strcat_end,
	check_strcat_empty_1,
	check_strcat_empty_2,
	check_strcat_empty_both,
	check_strcat_return,
	//check_strcat_overlap_easy,
	check_strcat_overlap_hard,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

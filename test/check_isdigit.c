/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:25:03 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 15:27:18 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_isdigit";

static void	check_isdigit_x(void)
{
	assert(ft_isdigit('x'), isdigit('x'));
}

static void	check_isdigit_X(void)
{
	assert(ft_isdigit('X'), isdigit('X'));
}

static void	check_isdigit_7(void)
{
	assert(ft_isdigit('7'), isdigit('7'));
}

static void	check_isdigit_0(void)
{
	assert(ft_isdigit('0'), isdigit('0'));
}

static void	check_isdigit_9(void)
{
	assert(ft_isdigit('9'), isdigit('9'));
}

static void	check_isdigit_slash(void)
{
	assert(ft_isdigit('/'), isdigit('/'));
}

static void	check_isdigit_colon(void)
{
	assert(ft_isdigit(':'), isdigit(':'));
}

static void	check_isdigit_newline(void)
{
	assert(ft_isdigit('\n'), isdigit('\n'));
}

static void	check_isdigit_nul(void)
{
	assert(ft_isdigit(0), isdigit(0));
}

static void	check_isdigit_negative(void)
{
	assert(ft_isdigit(-42), isdigit(-42));
}

static void	check_isdigit_char_max(void)
{
	assert(ft_isdigit(CHAR_MAX), isdigit(CHAR_MAX));
}

static void	check_isdigit_int_max(void)
{
	assert(ft_isdigit(INT_MAX), isdigit(INT_MAX));
}

static void	check_isdigit_uint_max(void)
{
	assert(ft_isdigit(UINT_MAX), isdigit(UINT_MAX));
}

static void	check_isdigit_int_min(void)
{
	assert(ft_isdigit(INT_MIN), isdigit(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_isdigit_x,
	check_isdigit_X,
	check_isdigit_7,
	check_isdigit_0,
	check_isdigit_9,
	check_isdigit_slash,
	check_isdigit_colon,
	check_isdigit_newline,
	check_isdigit_nul,
	check_isdigit_negative,
	check_isdigit_char_max,
	check_isdigit_int_max,
	check_isdigit_uint_max,
	check_isdigit_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 16:28:02 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_isalnum";

static void	check_isalnum_x(void)
{
	assert(ft_isalnum('x'), isalnum('x'));
}

static void	check_isalnum_X(void)
{
	assert(ft_isalnum('X'), isalnum('X'));
}

static void	check_isalnum_A(void)
{
	assert(ft_isalnum('A'), isalnum('A'));
}

static void	check_isalnum_Z(void)
{
	assert(ft_isalnum('Z'), isalnum('Z'));
}

static void	check_isalnum_a(void)
{
	assert(ft_isalnum('a'), isalnum('a'));
}

static void	check_isalnum_z(void)
{
	assert(ft_isalnum('z'), isalnum('z'));
}

static void	check_isalnum_at(void)
{
	assert(ft_isalnum('@'), isalnum('@'));
}

static void	check_isalnum_bracket(void)
{
	assert(ft_isalnum('['), isalnum('['));
}

static void	check_isalnum_backquote(void)
{
	assert(ft_isalnum('`'), isalnum('`'));
}

static void	check_isalnum_curly(void)
{
	assert(ft_isalnum('{'), isalnum('{'));
}

static void	check_isalnum_7(void)
{
	assert(ft_isalnum('7'), isalnum('7'));
}

static void	check_isalnum_0(void)
{
	assert(ft_isalnum('0'), isalnum('0'));
}

static void	check_isalnum_9(void)
{
	assert(ft_isalnum('9'), isalnum('9'));
}

static void	check_isalnum_slash(void)
{
	assert(ft_isalnum('/'), isalnum('/'));
}

static void	check_isalnum_colon(void)
{
	assert(ft_isalnum(':'), isalnum(':'));
}

static void	check_isalnum_newline(void)
{
	assert(ft_isalnum('\n'), isalnum('\n'));
}

static void	check_isalnum_nul(void)
{
	assert(ft_isalnum(0), isalnum(0));
}

static void	check_isalnum_negative(void)
{
	assert(ft_isalnum(-42), isalnum(-42));
}

static void	check_isalnum_char_max(void)
{
	assert(ft_isalnum(CHAR_MAX), isalnum(CHAR_MAX));
}

static void	check_isalnum_int_max(void)
{
	assert(ft_isalnum(INT_MAX), isalnum(INT_MAX));
}

static void	check_isalnum_uint_max(void)
{
	assert(ft_isalnum(UINT_MAX), isalnum(UINT_MAX));
}

static void	check_isalnum_int_min(void)
{
	assert(ft_isalnum(INT_MIN), isalnum(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_isalnum_x,
	check_isalnum_X,
	check_isalnum_A,
	check_isalnum_Z,
	check_isalnum_a,
	check_isalnum_z,
	check_isalnum_at,
	check_isalnum_bracket,
	check_isalnum_backquote,
	check_isalnum_curly,
	check_isalnum_z,
	check_isalnum_7,
	check_isalnum_0,
	check_isalnum_9,
	check_isalnum_slash,
	check_isalnum_colon,
	check_isalnum_newline,
	check_isalnum_nul,
	check_isalnum_negative,
	check_isalnum_char_max,
	check_isalnum_int_max,
	check_isalnum_uint_max,
	check_isalnum_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

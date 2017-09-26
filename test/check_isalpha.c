/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:25:03 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 16:19:44 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_isalpha";

static void	check_isalpha_x(void)
{
	assert(ft_isalpha('x'), isalpha('x'));
}

static void	check_isalpha_X(void)
{
	assert(ft_isalpha('X'), isalpha('X'));
}

static void	check_isalpha_A(void)
{
	assert(ft_isalpha('A'), isalpha('A'));
}

static void	check_isalpha_Z(void)
{
	assert(ft_isalpha('Z'), isalpha('Z'));
}

static void	check_isalpha_a(void)
{
	assert(ft_isalpha('a'), isalpha('a'));
}

static void	check_isalpha_z(void)
{
	assert(ft_isalpha('z'), isalpha('z'));
}

static void	check_isalpha_at(void)
{
	assert(ft_isalpha('@'), isalpha('@'));
}

static void	check_isalpha_bracket(void)
{
	assert(ft_isalpha('['), isalpha('['));
}

static void	check_isalpha_backquote(void)
{
	assert(ft_isalpha('`'), isalpha('`'));
}

static void	check_isalpha_curly(void)
{
	assert(ft_isalpha('{'), isalpha('{'));
}

static void	check_isalpha_7(void)
{
	assert(ft_isalpha('7'), isalpha('7'));
}

static void	check_isalpha_0(void)
{
	assert(ft_isalpha('0'), isalpha('0'));
}

static void	check_isalpha_9(void)
{
	assert(ft_isalpha('9'), isalpha('9'));
}

static void	check_isalpha_slash(void)
{
	assert(ft_isalpha('/'), isalpha('/'));
}

static void	check_isalpha_colon(void)
{
	assert(ft_isalpha(':'), isalpha(':'));
}

static void	check_isalpha_newline(void)
{
	assert(ft_isalpha('\n'), isalpha('\n'));
}

static void	check_isalpha_nul(void)
{
	assert(ft_isalpha(0), isalpha(0));
}

static void	check_isalpha_negative(void)
{
	assert(ft_isalpha(-42), isalpha(-42));
}

static void	check_isalpha_char_max(void)
{
	assert(ft_isalpha(CHAR_MAX), isalpha(CHAR_MAX));
}

static void	check_isalpha_int_max(void)
{
	assert(ft_isalpha(INT_MAX), isalpha(INT_MAX));
}

static void	check_isalpha_uint_max(void)
{
	assert(ft_isalpha(UINT_MAX), isalpha(UINT_MAX));
}

static void	check_isalpha_int_min(void)
{
	assert(ft_isalpha(INT_MIN), isalpha(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_isalpha_x,
	check_isalpha_X,
	check_isalpha_A,
	check_isalpha_Z,
	check_isalpha_a,
	check_isalpha_z,
	check_isalpha_at,
	check_isalpha_bracket,
	check_isalpha_backquote,
	check_isalpha_curly,
	check_isalpha_z,
	check_isalpha_7,
	check_isalpha_0,
	check_isalpha_9,
	check_isalpha_slash,
	check_isalpha_colon,
	check_isalpha_newline,
	check_isalpha_nul,
	check_isalpha_negative,
	check_isalpha_char_max,
	check_isalpha_int_max,
	check_isalpha_uint_max,
	check_isalpha_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

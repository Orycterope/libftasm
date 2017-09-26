/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 16:55:54 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_isprint";

static void	check_isprint_x(void)
{
	assert(ft_isprint('x'), isprint('x'));
}

static void	check_isprint_X(void)
{
	assert(ft_isprint('X'), isprint('X'));
}

static void	check_isprint_A(void)
{
	assert(ft_isprint('A'), isprint('A'));
}

static void	check_isprint_Z(void)
{
	assert(ft_isprint('Z'), isprint('Z'));
}

static void	check_isprint_a(void)
{
	assert(ft_isprint('a'), isprint('a'));
}

static void	check_isprint_z(void)
{
	assert(ft_isprint('z'), isprint('z'));
}

static void	check_isprint_at(void)
{
	assert(ft_isprint('@'), isprint('@'));
}

static void	check_isprint_bracket(void)
{
	assert(ft_isprint('['), isprint('['));
}

static void	check_isprint_backquote(void)
{
	assert(ft_isprint('`'), isprint('`'));
}

static void	check_isprint_curly(void)
{
	assert(ft_isprint('{'), isprint('{'));
}

static void	check_isprint_7(void)
{
	assert(ft_isprint('7'), isprint('7'));
}

static void	check_isprint_0(void)
{
	assert(ft_isprint('0'), isprint('0'));
}

static void	check_isprint_9(void)
{
	assert(ft_isprint('9'), isprint('9'));
}

static void	check_isprint_slash(void)
{
	assert(ft_isprint('/'), isprint('/'));
}

static void	check_isprint_colon(void)
{
	assert(ft_isprint(':'), isprint(':'));
}

static void	check_isprint_tilde(void)
{
	assert(ft_isprint('~'), isprint('~'));
}

static void	check_isprint_newline(void)
{
	assert(ft_isprint('\n'), isprint('\n'));
}

static void	check_isprint_nul(void)
{
	assert(ft_isprint(0), isprint(0));
}

static void	check_isprint_del(void)
{
	assert(ft_isprint(127), isprint(127));
}

static void	check_isprint_128(void)
{
	assert(ft_isprint(128), isprint(128));
}

static void	check_isprint_negative(void)
{
	assert(ft_isprint(-42), isprint(-42));
}

static void	check_isprint_char_max(void)
{
	assert(ft_isprint(CHAR_MAX), isprint(CHAR_MAX));
}

static void	check_isprint_int_max(void)
{
	assert(ft_isprint(INT_MAX), isprint(INT_MAX));
}

static void	check_isprint_uint_max(void)
{
	assert(ft_isprint(UINT_MAX), isprint(UINT_MAX));
}

static void	check_isprint_int_min(void)
{
	assert(ft_isprint(INT_MIN), isprint(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_isprint_x,
	check_isprint_X,
	check_isprint_A,
	check_isprint_Z,
	check_isprint_a,
	check_isprint_z,
	check_isprint_at,
	check_isprint_bracket,
	check_isprint_backquote,
	check_isprint_curly,
	check_isprint_z,
	check_isprint_7,
	check_isprint_0,
	check_isprint_9,
	check_isprint_slash,
	check_isprint_colon,
	check_isprint_tilde,
	check_isprint_newline,
	check_isprint_nul,
	check_isprint_del,
	check_isprint_128,
	check_isprint_negative,
	check_isprint_char_max,
	check_isprint_int_max,
	check_isprint_uint_max,
	check_isprint_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

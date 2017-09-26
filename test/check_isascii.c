/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 16:49:09 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_isascii";

static void	check_isascii_x(void)
{
	assert(ft_isascii('x'), isascii('x'));
}

static void	check_isascii_X(void)
{
	assert(ft_isascii('X'), isascii('X'));
}

static void	check_isascii_A(void)
{
	assert(ft_isascii('A'), isascii('A'));
}

static void	check_isascii_Z(void)
{
	assert(ft_isascii('Z'), isascii('Z'));
}

static void	check_isascii_a(void)
{
	assert(ft_isascii('a'), isascii('a'));
}

static void	check_isascii_z(void)
{
	assert(ft_isascii('z'), isascii('z'));
}

static void	check_isascii_at(void)
{
	assert(ft_isascii('@'), isascii('@'));
}

static void	check_isascii_bracket(void)
{
	assert(ft_isascii('['), isascii('['));
}

static void	check_isascii_backquote(void)
{
	assert(ft_isascii('`'), isascii('`'));
}

static void	check_isascii_curly(void)
{
	assert(ft_isascii('{'), isascii('{'));
}

static void	check_isascii_7(void)
{
	assert(ft_isascii('7'), isascii('7'));
}

static void	check_isascii_0(void)
{
	assert(ft_isascii('0'), isascii('0'));
}

static void	check_isascii_9(void)
{
	assert(ft_isascii('9'), isascii('9'));
}

static void	check_isascii_slash(void)
{
	assert(ft_isascii('/'), isascii('/'));
}

static void	check_isascii_colon(void)
{
	assert(ft_isascii(':'), isascii(':'));
}

static void	check_isascii_newline(void)
{
	assert(ft_isascii('\n'), isascii('\n'));
}

static void	check_isascii_nul(void)
{
	assert(ft_isascii(0), isascii(0));
}

static void	check_isascii_del(void)
{
	assert(ft_isascii(127), isascii(127));
}

static void	check_isascii_128(void)
{
	assert(ft_isascii(128), isascii(128));
}

static void	check_isascii_negative(void)
{
	assert(ft_isascii(-42), isascii(-42));
}

static void	check_isascii_char_max(void)
{
	assert(ft_isascii(CHAR_MAX), isascii(CHAR_MAX));
}

static void	check_isascii_int_max(void)
{
	assert(ft_isascii(INT_MAX), isascii(INT_MAX));
}

static void	check_isascii_uint_max(void)
{
	assert(ft_isascii(UINT_MAX), isascii(UINT_MAX));
}

static void	check_isascii_int_min(void)
{
	assert(ft_isascii(INT_MIN), isascii(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_isascii_x,
	check_isascii_X,
	check_isascii_A,
	check_isascii_Z,
	check_isascii_a,
	check_isascii_z,
	check_isascii_at,
	check_isascii_bracket,
	check_isascii_backquote,
	check_isascii_curly,
	check_isascii_z,
	check_isascii_7,
	check_isascii_0,
	check_isascii_9,
	check_isascii_slash,
	check_isascii_colon,
	check_isascii_newline,
	check_isascii_nul,
	check_isascii_del,
	check_isascii_128,
	check_isascii_negative,
	check_isascii_char_max,
	check_isascii_int_max,
	check_isascii_uint_max,
	check_isascii_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

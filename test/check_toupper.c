/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_toupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 17:22:44 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_toupper";

static void	check_toupper_x(void)
{
	assert(ft_toupper('x'), toupper('x'));
}

static void	check_toupper_X(void)
{
	assert(ft_toupper('X'), toupper('X'));
}

static void	check_toupper_A(void)
{
	assert(ft_toupper('A'), toupper('A'));
}

static void	check_toupper_Z(void)
{
	assert(ft_toupper('Z'), toupper('Z'));
}

static void	check_toupper_a(void)
{
	assert(ft_toupper('a'), toupper('a'));
}

static void	check_toupper_z(void)
{
	assert(ft_toupper('z'), toupper('z'));
}

static void	check_toupper_at(void)
{
	assert(ft_toupper('@'), toupper('@'));
}

static void	check_toupper_bracket(void)
{
	assert(ft_toupper('['), toupper('['));
}

static void	check_toupper_backquote(void)
{
	assert(ft_toupper('`'), toupper('`'));
}

static void	check_toupper_curly(void)
{
	assert(ft_toupper('{'), toupper('{'));
}

static void	check_toupper_7(void)
{
	assert(ft_toupper('7'), toupper('7'));
}

static void	check_toupper_0(void)
{
	assert(ft_toupper('0'), toupper('0'));
}

static void	check_toupper_9(void)
{
	assert(ft_toupper('9'), toupper('9'));
}

static void	check_toupper_slash(void)
{
	assert(ft_toupper('/'), toupper('/'));
}

static void	check_toupper_colon(void)
{
	assert(ft_toupper(':'), toupper(':'));
}

static void	check_toupper_tilde(void)
{
	assert(ft_toupper('~'), toupper('~'));
}

static void	check_toupper_newline(void)
{
	assert(ft_toupper('\n'), toupper('\n'));
}

static void	check_toupper_nul(void)
{
	assert(ft_toupper(0), toupper(0));
}

static void	check_toupper_eof(void)
{
	assert(ft_toupper(EOF), toupper(EOF));
}

static void	check_toupper_del(void)
{
	assert(ft_toupper(127), toupper(127));
}

static void	check_toupper_128(void)
{
	assert(ft_toupper(128), toupper(128));
}

static void	check_toupper_negative(void)
{
	assert(ft_toupper(-42), toupper(-42));
}

static void	check_toupper_char_max(void)
{
	assert(ft_toupper(CHAR_MAX), toupper(CHAR_MAX));
}

static void	check_toupper_int_max(void)
{
	assert(ft_toupper(INT_MAX), toupper(INT_MAX));
}

static void	check_toupper_uint_max(void)
{
	assert(ft_toupper(UINT_MAX), toupper(UINT_MAX));
}

static void	check_toupper_int_min(void)
{
	assert(ft_toupper(INT_MIN), toupper(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_toupper_x,
	check_toupper_X,
	check_toupper_A,
	check_toupper_Z,
	check_toupper_a,
	check_toupper_z,
	check_toupper_at,
	check_toupper_bracket,
	check_toupper_backquote,
	check_toupper_curly,
	check_toupper_z,
	check_toupper_7,
	check_toupper_0,
	check_toupper_9,
	check_toupper_slash,
	check_toupper_colon,
	check_toupper_tilde,
	check_toupper_newline,
	check_toupper_nul,
	check_toupper_eof,
	check_toupper_del,
	check_toupper_128,
	check_toupper_negative,
	check_toupper_char_max,
	check_toupper_int_max,
	check_toupper_uint_max,
	check_toupper_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

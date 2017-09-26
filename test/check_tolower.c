/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/20 17:27:15 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>

char	*g_test_name = "ft_tolower";

static void	check_tolower_x(void)
{
	assert(ft_tolower('x'), tolower('x'));
}

static void	check_tolower_X(void)
{
	assert(ft_tolower('X'), tolower('X'));
}

static void	check_tolower_A(void)
{
	assert(ft_tolower('A'), tolower('A'));
}

static void	check_tolower_Z(void)
{
	assert(ft_tolower('Z'), tolower('Z'));
}

static void	check_tolower_a(void)
{
	assert(ft_tolower('a'), tolower('a'));
}

static void	check_tolower_z(void)
{
	assert(ft_tolower('z'), tolower('z'));
}

static void	check_tolower_at(void)
{
	assert(ft_tolower('@'), tolower('@'));
}

static void	check_tolower_bracket(void)
{
	assert(ft_tolower('['), tolower('['));
}

static void	check_tolower_backquote(void)
{
	assert(ft_tolower('`'), tolower('`'));
}

static void	check_tolower_curly(void)
{
	assert(ft_tolower('{'), tolower('{'));
}

static void	check_tolower_7(void)
{
	assert(ft_tolower('7'), tolower('7'));
}

static void	check_tolower_0(void)
{
	assert(ft_tolower('0'), tolower('0'));
}

static void	check_tolower_9(void)
{
	assert(ft_tolower('9'), tolower('9'));
}

static void	check_tolower_slash(void)
{
	assert(ft_tolower('/'), tolower('/'));
}

static void	check_tolower_colon(void)
{
	assert(ft_tolower(':'), tolower(':'));
}

static void	check_tolower_tilde(void)
{
	assert(ft_tolower('~'), tolower('~'));
}

static void	check_tolower_newline(void)
{
	assert(ft_tolower('\n'), tolower('\n'));
}

static void	check_tolower_nul(void)
{
	assert(ft_tolower(0), tolower(0));
}

static void	check_tolower_eof(void)
{
	assert(ft_tolower(EOF), tolower(EOF));
}

static void	check_tolower_del(void)
{
	assert(ft_tolower(127), tolower(127));
}

static void	check_tolower_128(void)
{
	assert(ft_tolower(128), tolower(128));
}

static void	check_tolower_negative(void)
{
	assert(ft_tolower(-42), tolower(-42));
}

static void	check_tolower_char_max(void)
{
	assert(ft_tolower(CHAR_MAX), tolower(CHAR_MAX));
}

static void	check_tolower_int_max(void)
{
	assert(ft_tolower(INT_MAX), tolower(INT_MAX));
}

static void	check_tolower_uint_max(void)
{
	assert(ft_tolower(UINT_MAX), tolower(UINT_MAX));
}

static void	check_tolower_int_min(void)
{
	assert(ft_tolower(INT_MIN), tolower(INT_MIN));
}

void 	(*check_functions[]) =
{
	check_tolower_x,
	check_tolower_X,
	check_tolower_A,
	check_tolower_Z,
	check_tolower_a,
	check_tolower_z,
	check_tolower_at,
	check_tolower_bracket,
	check_tolower_backquote,
	check_tolower_curly,
	check_tolower_z,
	check_tolower_7,
	check_tolower_0,
	check_tolower_9,
	check_tolower_slash,
	check_tolower_colon,
	check_tolower_tilde,
	check_tolower_newline,
	check_tolower_nul,
	check_tolower_eof,
	check_tolower_del,
	check_tolower_128,
	check_tolower_negative,
	check_tolower_char_max,
	check_tolower_int_max,
	check_tolower_uint_max,
	check_tolower_int_min,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

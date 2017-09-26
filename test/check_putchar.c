/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_putcharhar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:47:51 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/25 21:20:50 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <limits.h>
#include <string.h>
#include <errno.h>

char	*g_test_name = "ft_putchar";

static void	check_putchar_x(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_putchar('x');
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	write(1, "x", 1);
	restore_stdout();

	assert(ret1, 'x');

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 64), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putchar_X(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_putchar('X');
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	write(1, "X", 1);
	restore_stdout();

	assert(ret1, 'X');

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 64), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putchar_newline(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_putchar('\n');
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	write(1, "\n", 1);
	restore_stdout();

	assert(ret1, '\n');

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 64), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putchar_nul(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_putchar(0);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	write(1, "", 1);
	restore_stdout();

	assert(ret1, 0);

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 64), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putchar_max_int(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;
	int		max = INT_MAX;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_putchar(INT_MAX);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	write(1, &max, 1);
	restore_stdout();

	assert(ret1, INT_MAX);

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 64), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putchar_min_int(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;
	int		min = INT_MIN;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_putchar(INT_MIN);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	write(1, &min, 1);
	restore_stdout();

	assert(ret1, INT_MIN);

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 64), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putchar_closed_fd(void)
{
	int	my_pipe1[2];
	int		ret1;

	redirect_stdout_to_pipe(my_pipe1);
	close(1);
	ret1 = ft_putchar('x');
	restore_stdout();

	assert(ret1, -1);

	close(my_pipe1[0]);
}

void 	(*check_functions[]) =
{
	check_putchar_x,
	check_putchar_X,
	check_putchar_newline,
	check_putchar_nul,
	check_putchar_max_int,
	check_putchar_min_int,
	check_putchar_closed_fd,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_puts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/25 14:33:15 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

char	*g_test_name = "ft_puts";

static void	check_puts_hello_world(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_puts("Hello World!");
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	ret2 =    puts("Hello World!");
	restore_stdout();

	assert(ret1, ret2);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_puts_one(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_puts("X");
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	ret2 =    puts("X");
	restore_stdout();

	assert(ret1, ret2);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_puts_zero(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_puts("");
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	ret2 =    puts("");
	restore_stdout();

	assert(ret1, ret2);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_puts_null(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_puts(NULL);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	ret2 =    puts(NULL);
	restore_stdout();

	assert(ret1, ret2);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_puts_long(void)
{
	char	str[4096] = { [ 0 ... 4094 ] = 'X', [ 4095 ] = 0 };
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[6000] = { 0 };
	char	buffer2[6000] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_puts(str);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	ret2 =    puts(str);
	restore_stdout();

	assert(ret1, ret2);

	ret1 = read(my_pipe1[0], buffer1, 6000);
	ret2 = read(my_pipe2[0], buffer2, 6000);

	assert(ret1, ret2);

	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_puts_no_change(void)
{
	char	str1[32] = { [ 0 ... 30 ] = 7, [ 31 ] = 0 };
	char	str2[32] = { [ 0 ... 30 ] = 7, [ 31 ] = 0 };
	int	my_pipe1[2];
	int	my_pipe2[2];
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ret1 = ft_puts(str1);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	ret2 =    puts(str2);
	restore_stdout();

	assert(ret1, ret2);
	assert(memcmp(str1, str2, 32), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_puts_closed_fd(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	int		ret1;
	int		ret2;
	int		close_ret_1;
	int		close_ret_2;
	int		errno_1;
	int		errno_2;

	redirect_stdout_to_pipe(my_pipe1);
	close_ret_1 = close(fileno(stdout));
	errno = 0;
	ret1 = ft_puts("Hello World!");
	errno_1 = errno;
	errno = 0;
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	close_ret_2 = close(fileno(stdout));
	errno = 0;
	ret2 =    puts("Hello World!");
	errno_2 = errno;
	errno = 0;
	restore_stdout();

	assert(close_ret_1, close_ret_2);
	assert(ret1, ret2);
	test(errno_1, errno_2);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

void 	(*check_functions[]) =
{
	check_puts_hello_world,
	check_puts_one,
	check_puts_zero,
	check_puts_null,
	check_puts_no_change,
	check_puts_long,
	check_puts_closed_fd,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

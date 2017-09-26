/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:27:30 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 13:10:33 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

char	*g_test_name = "ft_putstr";

static void	check_putstr_hello_world(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ft_putstr("Hello World!");
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	   printf("Hello World!");
	fflush(stdout);
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_putstr_one(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ft_putstr("X");
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	   printf("X");
	fflush(stdout);
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_putstr_zero(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ft_putstr("");
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	   printf("%s", "");
	fflush(stdout);
	restore_stdout();

	close(my_pipe1[1]);
	close(my_pipe2[1]);

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
}

static void	check_putstr_null(void)
{
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[64] = { 0 };
	char	buffer2[64] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ft_putstr(NULL);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	   printf("%s", NULL);
	fflush(stdout);
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 64);
	ret2 = read(my_pipe2[0], buffer2, 64);

	assert(ret1, ret2);
	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_putstr_long(void)
{
	char	str[4096] = { [ 0 ... 4094 ] = 'X', [ 4095 ] = 0 };
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[6000] = { 0 };
	char	buffer2[6000] = { 0 };
	int		ret1;
	int		ret2;

	redirect_stdout_to_pipe(my_pipe1);
	ft_putstr(str);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	   printf("%s", str);
	fflush(stdout);
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 6000);
	ret2 = read(my_pipe2[0], buffer2, 6000);

	assert(ret1, ret2);

	assert(strcmp(buffer1, buffer2), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

static void	check_putstr_no_change(void)
{
	char	str1[32] = { [ 0 ... 30 ] = 7, [ 31 ] = 0 };
	char	str2[32] = { [ 0 ... 30 ] = 7, [ 31 ] = 0 };
	int	my_pipe1[2];
	int	my_pipe2[2];

	redirect_stdout_to_pipe(my_pipe1);
	ft_putstr(str1);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	   printf("%s", str2);
	fflush(stdout);
	restore_stdout();

	assert(memcmp(str1, str2, 32), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
}

void 	(*check_functions[]) =
{
	check_putstr_hello_world,
	check_putstr_one,
	check_putstr_zero,
	check_putstr_null,
	check_putstr_no_change,
	check_putstr_long,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

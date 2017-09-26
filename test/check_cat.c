/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:03:19 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 16:31:12 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*g_test_name = "ft_cat ";

static void	check_cat_hello_world(void)
{
	int	pipe_src1[2];
	int	pipe_src2[2];
	int	pipe_dest[2];
	char	buffer1[4096] = { 0 };
	char	buffer2[4096] = { 0 };
	int	ret1;
	int	ret2;

	pipe(pipe_src1);
	write(pipe_src1[1], "Hello World!", 12);
	close(pipe_src1[1]);

	pipe(pipe_src2);
	write(pipe_src2[1], "Hello World!", 12);
	close(pipe_src2[1]);

	redirect_stdout_to_pipe(pipe_dest);
	ft_cat(pipe_src1[0]);
	restore_stdout();

	ret1 = read(pipe_dest[0], buffer1, 4096);
	ret2 = read(pipe_src2[0], buffer2, 4096);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 4096), 0);

	ft_cat(pipe_src1[0]);

	close(pipe_dest[1]);

	ret1 = read(pipe_dest[0], buffer1, 4096);
	ret2 = read(pipe_src2[0], buffer2, 4096);

	assert(memcmp(buffer1, buffer2, 4096), 0);
	assert(ret1, ret2);

	close(pipe_src1[0]);
	close(pipe_src2[0]);
	close(pipe_dest[0]);
}

static void	check_cat_one(void)
{
	int	pipe_src1[2];
	int	pipe_src2[2];
	int	pipe_dest[2];
	char	buffer1[4096] = { 0 };
	char	buffer2[4096] = { 0 };
	int	ret1;
	int	ret2;

	pipe(pipe_src1);
	write(pipe_src1[1], "X", 1);
	close(pipe_src1[1]);

	pipe(pipe_src2);
	write(pipe_src2[1], "X", 1);
	close(pipe_src2[1]);

	redirect_stdout_to_pipe(pipe_dest);
	ft_cat(pipe_src1[0]);
	restore_stdout();

	ret1 = read(pipe_dest[0], buffer1, 4096);
	ret2 = read(pipe_src2[0], buffer2, 4096);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 4096), 0);

	ft_cat(pipe_src1[0]);

	close(pipe_dest[1]);

	ret1 = read(pipe_dest[0], buffer1, 4096);
	ret2 = read(pipe_src2[0], buffer2, 4096);

	assert(memcmp(buffer1, buffer2, 4096), 0);
	assert(ret1, ret2);

	close(pipe_src1[0]);
	close(pipe_src2[0]);
	close(pipe_dest[0]);
}

static void	check_cat_zero(void)
{
	int	pipe_src1[2];
	int	pipe_src2[2];
	int	pipe_dest[2];
	char	buffer1[4096] = { 0 };
	char	buffer2[4096] = { 0 };
	int	ret1;
	int	ret2;

	pipe(pipe_src1);
	write(pipe_src1[1], "Hello World!", 0);
	close(pipe_src1[1]);

	pipe(pipe_src2);
	write(pipe_src2[1], "Hello World!", 0);
	close(pipe_src2[1]);

	redirect_stdout_to_pipe(pipe_dest);
	ft_cat(pipe_src1[0]);
	restore_stdout();

	close(pipe_dest[1]);

	ret1 = read(pipe_dest[0], buffer1, 4096);
	ret2 = read(pipe_src2[0], buffer2, 4096);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 4096), 0);

	close(pipe_src1[0]);
	close(pipe_src2[0]);
	close(pipe_dest[0]);
}

static void	check_cat_long(void)
{
	int		i;
	int	pipe_src1[2];
	int	pipe_src2[2];
	int	pipe_dest[2];
	char	buffer1[8192] = { 0 };
	char	buffer2[8192] = { 0 };
	int	ret1;
	int	ret2;

	pipe(pipe_src1);
	pipe(pipe_src2);

	i = -20;
	while (++i < 10000)
	{
		write(pipe_src1[1], &i, sizeof(i));
		write(pipe_src2[1], &i, sizeof(i));
	}

	close(pipe_src1[1]);
	close(pipe_src2[1]);

	redirect_stdout_to_pipe(pipe_dest);
	ft_cat(pipe_src1[0]);
	restore_stdout();

	close(pipe_dest[1]);

	do {
		ret1 = read(pipe_dest[0], buffer1, 8192);
		ret2 = read(pipe_src2[0], buffer2, 8192);
		assert(ret1, ret2);
		assert(memcmp(buffer1, buffer2, 8192), 0);
	} while (ret1 > 0);

	close(pipe_src1[0]);
	close(pipe_src2[0]);
	close(pipe_dest[0]);
}

static void	check_cat_bad_fd(void)
{
	int	pipe_dest[2];

	redirect_stdout_to_pipe(pipe_dest);
	ft_cat(-1);
	restore_stdout();

	assert(1, 1);

	close(pipe_dest[1]);
	close(pipe_dest[0]);
}

static void check_cat_auteur(void)
{
	int		fd;
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[4096] = { 0 };
	char	buffer2[4096] = { 0 };
	int	ret1;
	int	ret2;

	fd = open("../auteur", O_RDONLY);
	assert(fd > 0, 1);

	redirect_stdout_to_pipe(my_pipe1);
	ft_cat(fd);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	system("cat ../auteur");
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 4096);
	ret2 = read(my_pipe2[0], buffer2, 4096);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 4096), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
	close(fd);
}

static void check_cat_source(void)
{
	int		fd;
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[8192] = { 0 };
	char	buffer2[8192] = { 0 };
	int	ret1;
	int	ret2;

	fd = open("./check_cat.c", O_RDONLY);
	assert(fd > 0, 1);

	redirect_stdout_to_pipe(my_pipe1);
	ft_cat(fd);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	system("cat ./check_cat.c");
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 8192);
	ret2 = read(my_pipe2[0], buffer2, 8192);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 8192), 0);

	close(my_pipe1[0]);
	close(my_pipe1[1]);
	close(my_pipe2[0]);
	close(my_pipe2[1]);
	close(fd);
}

static void check_cat_eof(void)
{
	int		fd;
	int	my_pipe1[2];
	int	my_pipe2[2];
	char	buffer1[4096] = { 0 };
	char	buffer2[4096] = { 0 };
	int	ret1;
	int	ret2;

	fd = open("../auteur", O_RDONLY);
	assert(fd > 0, 1);

	redirect_stdout_to_pipe(my_pipe1);
	ft_cat(fd);
	restore_stdout();

	redirect_stdout_to_pipe(my_pipe2);
	system("cat ../auteur");
	restore_stdout();

	ret1 = read(my_pipe1[0], buffer1, 4096);
	ret2 = read(my_pipe2[0], buffer2, 4096);

	assert(ret1, ret2);
	assert(memcmp(buffer1, buffer2, 4096), 0);

	ret1 = close(my_pipe1[1]);
	ret2 = close(my_pipe2[1]);
	assert(ret1, ret2);

	ret1 = read(my_pipe1[0], buffer1, 4096);
	ret2 = read(my_pipe2[0], buffer2, 4096);

	assert(ret1, ret2);

	close(my_pipe1[0]);
	close(my_pipe2[0]);
	close(fd);
}

void 	(*check_functions[]) =
{
	check_cat_hello_world,
	check_cat_one,
	check_cat_zero,
	check_cat_long,
	check_cat_bad_fd,
	check_cat_auteur,
	check_cat_source,
	check_cat_eof,
};

int		check_functions_number = sizeof(check_functions) / sizeof(check_functions[0]);

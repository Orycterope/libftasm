/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:22:21 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/25 14:07:04 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libfts.h"

extern char	*g_test_name;
extern 		void (*check_functions[])(void);
extern int	check_functions_number;

int			g_stdout_bkp;

void		redirect_stdout_to_pipe(int my_pipe[2])
{
	// save stdout fd
	g_stdout_bkp = dup(fileno(stdout));

	// creates a pipe : write p[1] --> p[0] read
	pipe(my_pipe);

	// stdout now is writing to pipe
	dup2(my_pipe[1], fileno(stdout));
}

void		restore_stdout(void)
{
	// restore stdout to console
	dup2(g_stdout_bkp, fileno(stdout));
}

int		main(void)
{
	int		i;

	printf("%s:\t", g_test_name);
	fflush(stdout);
	i = -1;
	while (++i < check_functions_number)
	{
		(*check_functions[i])();
	}
	printf("\n");
	fflush(stdout);
	return (0);
}

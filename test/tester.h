/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:30:26 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/25 13:51:09 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <unistd.h>
# include <stdio.h>
# include "libfts.h"

# define assert(x, y) 											\
		do {													\
			if ((x) == (y))										\
				printf(".");									\
			else												\
				printf("\n%s:%d Failed for %s\n",				\
						__FILE__,								\
						__LINE__,								\
						__func__);								\
			fflush(stdout);										\
		} while (0)

# define test(x, y) 											\
		do {													\
			if ((x) == (y))										\
				printf(".");									\
			else												\
				printf("~");									\
			fflush(stdout);										\
		} while (0)


void	redirect_stdout_to_pipe(int my_pipe[2]);
void	restore_stdout(void);

#endif

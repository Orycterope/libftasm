/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:25:37 by tvermeil          #+#    #+#             */
/*   Updated: 2017/09/26 16:26:42 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_putchar(int c);
int		ft_puts(char *s);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *s);
char	*ft_strcat(char *s1, char *s2);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
int		ft_strcmp(void *s1, void *s2);
int		ft_strncmp(void *s1, void *s2, size_t n);
char	*ft_strdup(char *s1);
void	ft_cat(int fd);

#endif

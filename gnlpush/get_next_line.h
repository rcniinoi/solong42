/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:25:55 by rchiewli          #+#    #+#             */
/*   Updated: 2022/07/27 21:24:40 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*ft_calloc_g(size_t count, size_t size);
int		ft_strlen_g(char *str, int mode);
char	*ft_getread(int fd, char **bigarray);
int		ft_chkread(int rd, char *str, int mode);
char	*ft_join(char *s1, char *s2, int mode, int freemode);
char	*ft_afternjoin(char *s1, char *s2);
void	*ft_freecondom1(char **bigarray, int fd);
void	*ft_freecondom2(int rd, char *ret);

#endif

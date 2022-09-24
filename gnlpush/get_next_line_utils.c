/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:41:38 by rchiewli          #+#    #+#             */
/*   Updated: 2022/07/27 21:26:31 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_g(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	dst = malloc(total);
	if (!dst)
		return (NULL);
	i = 0;
	while (total--)
	{
		dst[i] = '\0';
		i++;
	}
	return ((void *)dst);
}

int	ft_strlen_g(char *str, int mode)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (mode == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i += 1;
	}
	else
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_join(char *s1, char *s2, int mode, int freemode)
{
	size_t	i;
	size_t	j;
	size_t	s2len;
	char	*newstr;

	if (mode == 1)
		s2len = ft_strlen_g(s2, 1);
	if (mode == 2)
		s2len = ft_strlen_g(s2, 3);
	newstr = ft_calloc_g(ft_strlen_g(s1, 1) + s2len + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (s1 && s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (j < s2len)
		newstr[i++] = s2[j++];
	if (s1 && s1[0] != '\0')
		free(s1);
	if (s2 && s2[0] != '\0' && freemode == 1)
		free(s2);
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_afternjoin(char	*s1, char *s2)
{
	char	*tmp;
	char	*newstr;
	size_t	i;
	size_t	tmplen;
	size_t	j;

	i = 0;
	j = 0;
	tmp = s2;
	tmplen = ft_strlen_g(s2, 1);
	newstr = ft_calloc_g(ft_strlen_g(s1, 3) + ft_strlen_g(tmp + tmplen, 2) + 1,
			sizeof(char *));
	while (s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (tmp[tmplen + j])
		newstr[i++] = tmp[tmplen + j++];
	if (s1 && s1[0] != '\0')
		free(s1);
	return (newstr);
}

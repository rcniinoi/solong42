/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:47:01 by rchiewli          #+#    #+#             */
/*   Updated: 2022/07/27 21:25:13 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

int	ft_chkread(int rd, char *str, int mode)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (mode == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n' || rd == 0)
			return (0);
		return (1);
	}
	return (0);
}

char	*ft_getread(int fd, char **bigarray)
{
	char	*buffer;
	size_t	rd;
	char	*ret;
	char	*fullbuffer;

	fullbuffer = NULL;
	rd = -1;
	if (bigarray[fd])
		fullbuffer = ft_join("", bigarray[fd], 2, 1);
	while (ft_chkread(rd, fullbuffer, 1) == 1)
	{
		buffer = ft_calloc_g(BUFFER_SIZE + 1, 1);
		rd = read(fd, buffer, BUFFER_SIZE);
		fullbuffer = ft_join(fullbuffer, buffer, 2, 0);
		free (buffer);
	}
	ret = ft_join("", fullbuffer, 1, 0);
	bigarray[fd] = ft_afternjoin("", fullbuffer);
	bigarray[fd] = ft_freecondom1(bigarray, fd);
	ret = ft_freecondom2(rd, ret);
	free(fullbuffer);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*bigarray[OPEN_MAX];
	char		*ret;
	size_t		i;

	i = 0;
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	ret = ft_getread(fd, bigarray);
	if (ret == NULL)
	{
		if (bigarray[fd])
		{
			free (bigarray[fd]);
			bigarray[fd] = NULL;
		}
	}
	return (ret);
}

void	*ft_freecondom1(char **bigarray, int fd)
{
	if (ft_strlen_g(bigarray[fd], 2) == 0)
	{
		free (bigarray[fd]);
		return (NULL);
	}
	return (bigarray[fd]);
}

void	*ft_freecondom2(int rd, char *ret)
{
	if (rd == 0 && ret[0] == '\0')
	{
		free (ret);
		return (NULL);
	}
	return (ret);
}

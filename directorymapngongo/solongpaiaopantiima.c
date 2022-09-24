/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongpaiaopantiima.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:29:28 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:41:45 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

char	**ft_gettmpmap(char *argv)
{
	int		openfd;
	int		i;
	int		lcount;
	char	**tmpmap;

	i = 0;
	lcount = ft_linecount(argv);
	tmpmap = malloc(sizeof(char *) * (lcount + 1));
	openfd = open(argv, O_RDWR);
	tmpmap[i] = get_next_line(openfd);
	while (tmpmap[i] != NULL)
	{
		i++;
		tmpmap[i] = get_next_line(openfd);
	}
	close(openfd);
	return (tmpmap);
}

t_start	ft_startpo(t_map *mapber)
{
	g_startpo.startx = 0;
	g_startpo.starty = 0;
	while ((g_startpo.starty < mapber->ymax))
	{
		while (mapber->mapbuff[g_startpo.starty][g_startpo.startx] != '\n' \
			&& mapber->mapbuff[g_startpo.starty][g_startpo.startx] != '\0')
		{
			if (mapber->mapbuff[g_startpo.starty][g_startpo.startx] == 'P')
				return (g_startpo);
			g_startpo.startx++;
		}
		g_startpo.startx = 0;
		g_startpo.starty++;
	}
	return (g_startpo);
}

char	*ft_strchr(char *s, int c)
{
	while ((*s != (char)c) && (*s != '\0'))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(1, &s[i++], 1);
}

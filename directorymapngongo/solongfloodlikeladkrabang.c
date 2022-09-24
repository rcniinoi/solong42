/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongfloodlikeladkrabang.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:22:24 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/24 21:22:40 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_fontoknuk(char *argv, t_map *mapber)
{
	char	**tmpmap;
	t_start	po;
	int		i;

	i = 0;
	po = ft_startpo(mapber);
	tmpmap = ft_gettmpmap(argv);
	if (ft_flood(tmpmap, po.starty, po.startx) == 1)
		ft_putstr("this map is good la la la la la la la\n");
	else
	{
		ft_putstr("map here here krai ja ma len ai ngo\n");
		while (tmpmap[i] != NULL)
			free(tmpmap[i++]);
		free (tmpmap);
		exit(1);
	}
	while (tmpmap[i] != NULL)
		free(tmpmap[i++]);
	free (tmpmap);
}

int	ft_flood(char **tmpmap, int y, int x)
{
	int	ok;

	ok = 0;
	if (ft_fillchk(tmpmap[y][x]) == 1)
	{
		if (tmpmap[y][x] == 'E')
			return (1);
		tmpmap[y][x] = 'F';
		ok = ft_flood(tmpmap, y, (x - 1));
		if (ok != 1)
			ok = ft_flood(tmpmap, y - 1, x);
		if (ok != 1)
			ok = ft_flood(tmpmap, y, x + 1);
		if (ok != 1)
			ok = ft_flood(tmpmap, y + 1, x);
	}
	return (ok);
}

int	ft_fillchk(char po)
{
	if (po == 'P' || po == '0' || po == 'C' || po == 'Z' \
		|| po == 'Y' || po == 'X' || po == 'W' || po == 'E')
		return (1);
	else
		return (0);
}

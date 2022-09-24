/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongmapchk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:29:22 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:29:27 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

int	ft_wallchknon(t_map *mapber, int y, int x)
{
	while (x < mapber->xmax)
	{
		if (mapber->mapbuff[y][x] != '1')
			return (ft_maiok("Wall neawnon"));
		x++;
	}
	return (1);
}

int	ft_wallchktung(t_map *mapber, int y, int x)
{
	while (y < mapber->ymax)
	{
		if (mapber->mapbuff[y][x] != '1')
			return (ft_maiok("Wall neawtung"));
		y++;
	}
	return (1);
}

int	ft_siileamchker(t_map *mapber)
{
	int	counter;
	int	line;

	counter = 0;
	line = 0;
	while (line < mapber->ymax)
	{
		while (mapber->mapbuff[line][counter] != '\n' \
			&& mapber->mapbuff[line][counter] != '\0')
			counter++;
		if (counter -1 != mapber->xmax)
			return (ft_maiok("4 leam chk"));
		counter = 0;
		line++;
	}
	return (1);
}

void	ft_wallchkall(t_map *mapber, char *argv)
{
	if (!ft_wallchknon(mapber, 0, 0) || !ft_wallchktung(mapber, 0, 0))
		exit(0);
	if (!ft_wallchknon(mapber, mapber->ymax, 0) \
		|| !ft_wallchktung(mapber, 0, mapber->xmax))
		exit(0);
	if (!ft_siileamchker(mapber))
		exit(0);
	if (!ft_cchk(mapber) || !ft_echk(mapber) || !ft_pchk(mapber))
		exit(0);
	ft_fontoknuk(argv, mapber);
}

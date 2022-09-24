/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongcepchk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:28:17 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:28:22 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

int	ft_cchk(t_map *mapber)
{
	int	i;
	int	line;
	int	r;

	line = 0;
	while ((line <= mapber->ymax))
	{
		i = 0;
		while (mapber->mapbuff[line][i] != '\n' \
			&& mapber->mapbuff[line][i] != '\0')
		{
			if (mapber->mapbuff[line][i] == 'C')
			{
				r = rand () % 3;
				g_mapber.mapbuff[line][i] = ('C' + 32 + r);
				g_frt.ccount++;
			}
			i++;
		}
		line++;
	}
	if (g_frt.ccount < 1)
		return (ft_maiok("C chk"));
	return (g_frt.ccount);
}

int	ft_echk(t_map *mapber)
{
	int	i;
	int	e;
	int	line;

	e = 0;
	line = 0;
	while ((line <= mapber->ymax))
	{
		i = 0;
		while (mapber->mapbuff[line][i] != '\n' \
			&& mapber->mapbuff[line][i] != '\0')
		{
			if (mapber->mapbuff[line][i] == 'E')
				e++;
			i++;
		}
		line++;
	}
	if (e != 1)
		return (ft_maiok("E chk"));
	return (1);
}

int	ft_pchk(t_map *mapber)
{
	int	i;
	int	p;
	int	line;

	p = 0;
	line = 0;
	while ((line <= mapber->ymax))
	{
		i = 0;
		while (mapber->mapbuff[line][i] != '\n' \
			&& mapber->mapbuff[line][i] != '\0')
		{
			if (mapber->mapbuff[line][i] == 'P')
				p++;
			i++;
		}
		line++;
	}
	if (p != 1)
		return (ft_maiok("P chk"));
	return (1);
}

int	ft_maiok(char *c)
{
	ft_printf(">>>>>[%s]>>>>>mai ok\n", c);
	return (0);
}

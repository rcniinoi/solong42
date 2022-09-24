/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongoutput2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:26:40 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 15:15:00 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_showfruit(t_map *g_mapber)
{
	ft_solongini();
	while (g_mapber->mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber->mapbuff[g_xy.y][g_xy.x] == '\n' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == '\0')
			ft_blocknl();
		else if (g_mapber->mapbuff[g_xy.y][g_xy.x] == 'c' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == 'd' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == 'e')
		{
			if (g_mapber->mapbuff[g_xy.y][g_xy.x] == 'c')
				ft_itowcep(g_tmlx.mlx, g_sp.reddown, g_sp.redup);
			if (g_mapber->mapbuff[g_xy.y][g_xy.x] == 'd')
				ft_itowcep(g_tmlx.mlx, g_sp.yellowdown, g_sp.yellowup);
			if (g_mapber->mapbuff[g_xy.y][g_xy.x] == 'e')
				ft_itowcep(g_tmlx.mlx, g_sp.violetdown, g_sp.violetup);
			g_xy.blockx += g_block;
			g_xy.x++;
		}
		else
		{
			g_xy.blockx += g_block;
			g_xy.x++;
		}
	}
}

void	ft_itowcep(void *mlx, char *imgvar, char *imgvar2)
{
	time_t	s;

	s = time(NULL) % 2;
	srand(time(NULL));
	if (s == 1)
		ft_itow(mlx, imgvar);
	else
		ft_itow(mlx, imgvar2);
}

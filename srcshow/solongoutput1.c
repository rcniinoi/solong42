/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongoutput1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:26:32 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 03:35:09 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_showmap(t_map *g_mapber)
{
	ft_solongini();
	while (g_mapber->mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber->mapbuff[g_xy.y][g_xy.x] == '1')
		{
			ft_itow(g_tmlx.mlx, g_sp.hinyai);
			g_xy.blockx += g_block;
			g_xy.x++;
		}
		else if (g_mapber->mapbuff[g_xy.y][g_xy.x] == '\n' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == '\0')
			ft_blocknl();
		else
		{
			g_xy.blockx += g_block;
			g_xy.x++;
		}
	}
}

void	ft_putground(t_map *g_mapber)
{
	ft_solongini();
	while (g_mapber->mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber->mapbuff[g_xy.y][g_xy.x] == '\n' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == '\0')
			ft_blocknl();
		else if (g_xy.y == 0)
		{
			ft_itow(g_tmlx.mlx, g_sp.naamhalf);
			g_xy.blockx += g_block;
			g_xy.x++;
		}
		else if (g_mapber->mapbuff[g_xy.y] != NULL)
		{
			ft_itow(g_tmlx.mlx, g_sp.naam);
			g_xy.blockx += g_block;
			g_xy.x++;
		}
	}
}

void	ft_blocknl(void)
{
			g_xy.blocky += g_block;
			g_xy.y++;
			g_xy.blockx = 0;
			g_xy.x = 0;
}

void	ft_showship(t_map *g_mapber, int direction)
{
	ft_solongini();
	while (g_mapber->mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber->mapbuff[g_xy.y][g_xy.x] == '\n' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == '\0')
			ft_blocknl();
		else if (g_mapber->mapbuff[g_xy.y][g_xy.x] == 'P')
		{
			if (direction == 13 || direction == 126)
				ft_itow(g_tmlx.mlx, g_sp.ruabon);
			else if (direction == 0 || direction == 123)
				ft_itow(g_tmlx.mlx, g_sp.rualeft);
			else if (direction == 1 || direction == 125)
				ft_itow(g_tmlx.mlx, g_sp.rualang);
			else if (direction == 2 || direction == 124)
				ft_itow(g_tmlx.mlx, g_sp.ruakwa);
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

void	ft_showexit(t_map *g_mapber)
{
	ft_solongini();
	while (g_mapber->mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber->mapbuff[g_xy.y][g_xy.x] == '\n' \
			|| g_mapber->mapbuff[g_xy.y][g_xy.x] == '\0')
			ft_blocknl();
		else if (g_mapber->mapbuff[g_xy.y][g_xy.x] == 'E')
		{
			ft_itow(g_tmlx.mlx, g_sp.hintun);
			if (g_frt.fruit >= g_frt.ccount)
				ft_itow(g_tmlx.mlx, g_sp.wfall);
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

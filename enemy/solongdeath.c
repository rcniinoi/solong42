/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongdeath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:12:23 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:12:33 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_showdeath(void *mlx)
{
	ft_solongini();
	while (g_mapber.mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber.mapbuff[g_xy.y][g_xy.x] == 'X')
		{
			ft_itow(mlx, g_sp.death);
			g_xy.blockx += g_block;
			g_xy.x++;
		}
		else if (g_mapber.mapbuff[g_xy.y][g_xy.x] == '\n' \
			|| g_mapber.mapbuff[g_xy.y][g_xy.x] == '\0')
			ft_blocknl();
		else
		{
			g_xy.blockx += g_block;
			g_xy.x++;
		}
	}
}

t_start	ft_xpo(t_map *mapber)
{
	g_xpo.startx = 0;
	g_xpo.starty = 0;
	while ((g_xpo.starty < mapber->ymax))
	{
		while (mapber->mapbuff[g_xpo.starty][g_xpo.startx] != '\n' \
			&& mapber->mapbuff[g_xpo.starty][g_xpo.startx] != '\0')
		{
			if (mapber->mapbuff[g_xpo.starty][g_xpo.startx] == 'X')
				return (g_xpo);
			g_xpo.startx++;
		}
		g_xpo.startx = 0;
		g_xpo.starty++;
	}
	return (g_xpo);
}

int	*ft_xmoveposition(int r)
{
	int	*move;

	move = malloc(sizeof(int *) * 2);
	ft_xpo(&g_mapber);
	move[0] = g_xpo.starty;
	move[1] = g_xpo.startx;
	if (r == 0)
		move[0] = g_xpo.starty - 1;
	else if (r == 1)
		move[1] = g_xpo.startx - 1;
	else if (r == 2)
		move[0] = g_xpo.starty + 1;
	else if (r == 3)
		move[1] = g_xpo.startx + 1;
	return (move);
}

void	ft_xgo(void)
{
	int	*move;
	int	i;
	int	r;

	r = rand () % 4;
	i = 0;
	while (i < 3)
	{
		move = ft_xmoveposition(r);
		if (g_mapber.mapbuff[g_xpo.starty][g_xpo.startx] == 'X' \
			&& ft_mvchk(move) == 1)
		{
			if (g_mapber.mapbuff[move[0]][move[1]] == 'P')
			{
				ft_putstr("you sinked\n");
				ft_free();
				free(move);
				exit(0);
			}
			g_mapber.mapbuff[g_xpo.starty][g_xpo.startx] = '0';
			g_mapber.mapbuff[move[0]][move[1]] = 'X';
		}
		i++;
	}
	free(move);
}

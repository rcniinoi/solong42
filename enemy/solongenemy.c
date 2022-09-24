/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongenemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:12:45 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:12:58 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_showcthulhu(void *mlx)
{
	ft_solongini();
	while (g_mapber.mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber.mapbuff[g_xy.y][g_xy.x] == 'Z')
		{
			ft_itow(mlx, g_sp.cthulhu);
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

t_start	ft_zpo(t_map *mapber)
{
	g_zpo.startx = 0;
	g_zpo.starty = 0;
	while ((g_zpo.starty < mapber->ymax))
	{
		while (mapber->mapbuff[g_zpo.starty][g_zpo.startx] != '\n' \
			&& mapber->mapbuff[g_zpo.starty][g_zpo.startx] != '\0')
		{
			if (mapber->mapbuff[g_zpo.starty][g_zpo.startx] == 'Z')
				return (g_zpo);
			g_zpo.startx++;
		}
		g_zpo.startx = 0;
		g_zpo.starty++;
	}
	return (g_zpo);
}

int	*ft_zmoveposition(void)
{
	int	*move;
	int	r;

	r = rand () % 4;
	move = malloc(sizeof(int *) * 2);
	ft_zpo(&g_mapber);
	move[0] = g_zpo.starty;
	move[1] = g_zpo.startx;
	if (r == 0)
		move[0] = g_zpo.starty - 1;
	else if (r == 1)
		move[1] = g_zpo.startx - 1;
	else if (r == 2)
		move[0] = g_zpo.starty + 1;
	else if (r == 3)
		move[1] = g_zpo.startx + 1;
	return (move);
}

void	ft_zgo(void)
{
	int	*move;
	int	i;

	i = 0;
	while (i < 4)
	{
		move = ft_zmoveposition();
		if (g_mapber.mapbuff[g_zpo.starty][g_zpo.startx] == 'Z' \
			&& ft_mvchk(move) == 1)
		{
			if (g_mapber.mapbuff[move[0]][move[1]] == 'P')
			{
				ft_putstr("you sinked\n");
				ft_free();
				free(move);
				exit(0);
			}
			g_mapber.mapbuff[g_zpo.starty][g_zpo.startx] = '0';
			g_mapber.mapbuff[move[0]][move[1]] = 'Z';
		}
		i++;
	}
	free(move);
}

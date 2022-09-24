/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solonghastur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:15:48 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:16:04 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_showhastur(void *mlx)
{
	ft_solongini();
	while (g_mapber.mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber.mapbuff[g_xy.y][g_xy.x] == 'Y')
		{
			ft_itow(mlx, g_sp.hastur);
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

t_start	ft_ypo(t_map *mapber)
{
	g_ypo.startx = 0;
	g_ypo.starty = 0;
	while ((g_ypo.starty < mapber->ymax))
	{
		while (mapber->mapbuff[g_ypo.starty][g_ypo.startx] != '\n' \
			&& mapber->mapbuff[g_ypo.starty][g_ypo.startx] != '\0')
		{
			if (mapber->mapbuff[g_ypo.starty][g_ypo.startx] == 'Y')
				return (g_ypo);
			g_ypo.startx++;
		}
		g_ypo.startx = 0;
		g_ypo.starty++;
	}
	return (g_ypo);
}

int	*ft_ymoveposition(void)
{
	int	*move;
	int	r;

	r = rand () % 4;
	move = malloc(sizeof(int *) * 2);
	ft_ypo(&g_mapber);
	move[0] = g_ypo.starty;
	move[1] = g_ypo.startx;
	move = movechieng(move, r);
	return (move);
}

void	ft_ygo(void)
{
	int	*move;
	int	i;

	i = 0;
	while (i < 2)
	{
		move = ft_ymoveposition();
		if (g_mapber.mapbuff[g_ypo.starty][g_ypo.startx] == 'Y' \
			&& ft_mvchk(move) == 1)
		{
			if (g_mapber.mapbuff[move[0]][move[1]] == 'P')
			{
				ft_putstr("you sinked\n");
				ft_free();
				free(move);
				exit(0);
			}
			g_mapber.mapbuff[g_ypo.starty][g_ypo.startx] = '0';
			g_mapber.mapbuff[move[0]][move[1]] = 'Y';
		}
		i++;
	}
	free(move);
}

int	*movechieng(int move[2], int r)
{
	if (r == 0)
	{
		move[0] = g_ypo.starty - 1;
		move[1] = g_ypo.startx - 1;
	}
	else if (r == 1)
	{
		move[0] = g_ypo.starty - 1;
		move[1] = g_ypo.startx + 1;
	}
	else if (r == 2)
	{
		move[0] = g_ypo.starty + 1;
		move[1] = g_ypo.startx + 1;
	}
	else if (r == 3)
	{
		move[0] = g_ypo.starty + 1;
		move[1] = g_ypo.startx - 1;
	}
	return (move);
}

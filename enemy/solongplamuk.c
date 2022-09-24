/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongplamuk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:16:19 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:19:39 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

void	ft_showplamuk(void *mlx)
{
	ft_solongini();
	while (g_mapber.mapbuff[g_xy.y] != NULL)
	{
		if (g_mapber.mapbuff[g_xy.y][g_xy.x] == 'W')
		{
			ft_itow(mlx, g_sp.plamuk);
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

int	*ft_wmoveposition(int i)
{
	int	*move;
	int	r;

	r = rand () % 4;
	move = malloc(sizeof(int *) * 2);
	move[0] = g_plamuk[i].starty;
	move[1] = g_plamuk[i].startx;
	if (r == 0)
		move[0] = g_plamuk[i].starty - 1;
	else if (r == 1)
		move[1] = g_plamuk[i].startx - 1;
	else if (r == 2)
		move[0] = g_plamuk[i].starty + 1;
	else if (r == 3)
		move[1] = g_plamuk[i].startx + 1;
	return (move);
}

void	ft_wgo(void)
{
	int	*move;
	int	i;
	int	count;

	count = ft_wchk(&g_mapber);
	i = 0;
	while (i < count)
	{
		move = ft_wmoveposition(i);
		if (g_mapber.mapbuff[g_plamuk[i].starty][g_plamuk[i].startx] == 'W' \
			&& ft_mvchk(move) == 1)
		{
			if (g_mapber.mapbuff[move[0]][move[1]] == 'P')
				ft_diefreeexit(move);
			g_mapber.mapbuff[g_plamuk[i].starty][g_plamuk[i].startx] = '0';
			g_mapber.mapbuff[move[0]][move[1]] = 'W';
		}
		i++;
	}
	if (count > 0)
		free(move);
}

void	ft_diefreeexit(int	*move)
{
	ft_putstr("you sinked\n");
	ft_free();
	free(move);
	exit(0);
}

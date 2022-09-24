/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solonghooker1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:57:32 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:34:16 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

int	mlx_close(void *ptr)
{
	(void) ptr;
	exit (0);
	return (0);
}

int	key_hooker(int keycode)
{
	ft_startpo(&g_mapber);
	g_count++;
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 \
		|| keycode == 123 || keycode == 124 || keycode == 125 \
		|| keycode == 126)
		ft_go(keycode);
	else if (keycode == 53)
		exit(0);
	ft_zgo();
	ft_ygo();
	ft_xgo();
	ft_plamukini(&g_mapber);
	ft_wgo();
	ft_printf("move === %d\n", g_count);
	ft_printf("fruit === %d\n", g_frt.fruit);
	return (0);
}

int	*ft_moveposition(int direction)
{
	int	*move;

	move = malloc(sizeof(int *) * 2);
	move[0] = g_startpo.starty;
	move[1] = g_startpo.startx;
	if (direction == 13 || direction == 126)
		move[0] = g_startpo.starty - 1;
	else if (direction == 0 || direction == 123)
		move[1] = g_startpo.startx - 1;
	else if (direction == 1 || direction == 125)
		move[0] = g_startpo.starty + 1;
	else if (direction == 2 || direction == 124)
		move[1] = g_startpo.startx + 1;
	return (move);
}

void	ft_go(int direction)
{
	int	*move;

	move = ft_moveposition(direction);
	if (g_mapber.mapbuff[g_startpo.starty][g_startpo.startx] == 'P' \
		&& g_mapber.mapbuff[move[0]][move[1]] != '1')
	{
		if (ft_movecondition2(move) == 1)
			g_frt.fruit++;
		else if (g_mapber.mapbuff[move[0]][move[1]] \
			== 'E' && g_frt.fruit >= g_frt.ccount)
			exit(0);
		else if (g_mapber.mapbuff[move[0]][move[1]] \
			== 'E' && g_frt.fruit <= g_frt.ccount)
			return ;
		else if (ft_movecondition(move) == 1)
			ft_diefreeexit(move);
		g_mapber.mapbuff[g_startpo.starty][g_startpo.startx] = '0';
		g_mapber.mapbuff[move[0]][move[1]] = 'P';
	}
	g_direction = direction;
	free(move);
}

int	key_looper(void)
{
	mlx_clear_window(g_tmlx.mlx, g_tmlx.mlx_win);
	ft_output(&g_mapber, g_direction);
	return (0);
}

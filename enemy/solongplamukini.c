/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongplamukini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:27:48 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:27:50 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

int	ft_wchk(t_map *mapber)
{
	int	i;
	int	line;
	int	count;

	count = 0;
	line = 0;
	while ((line < mapber->ymax))
	{
		i = 0;
		while (mapber->mapbuff[line][i] != '\n' \
			&& mapber->mapbuff[line][i] != '\0')
		{
			if (mapber->mapbuff[line][i] == 'W')
				count++;
			i++;
		}
		line++;
	}
	return (count);
}

void	ft_plamukini(t_map *mapber)
{
	int	i;
	int	count;
	int	row;
	int	col;

	row = 0;
	col = 0;
	i = 0;
	count = ft_wchk(mapber);
	while (row <= mapber->ymax && i < count)
	{
		while (mapber->mapbuff[row][col] != '\n' \
			&& mapber->mapbuff[row][col] != '\0')
		{
			if (mapber->mapbuff[row][col] == 'W')
			{
				g_plamuk[i].starty = row;
				g_plamuk[i].startx = col;
				i++;
			}
			col++;
		}
		col = 0;
		row++;
	}
}

int	ft_mvchk(int	*move)
{
	if (g_mapber.mapbuff[move[0]][move[1]] != '1' \
	&& g_mapber.mapbuff[move[0]][move[1]] != 'c'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'd'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'e'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'E'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'W'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'Y'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'Z'
	&& g_mapber.mapbuff[move[0]][move[1]] != 'X')
		return (1);
	else
		return (0);
}

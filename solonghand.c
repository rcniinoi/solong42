/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solonghand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:28:31 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/24 04:47:35 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "solong.h"

void	ft_printexit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	ft_mandamap(t_map *mapber)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while ((y <= mapber->ymax))
	{
		while (mapber->mapbuff[y][x] != '\n' \
			&& mapber->mapbuff[y][x] != '\0')
		{
			if (mapber->mapbuff[y][x] != '1' \
				&& ft_fillchk(mapber->mapbuff[y][x]) != 1 \
				&& mapber->mapbuff[y][x] != 'c' \
				&& mapber->mapbuff[y][x] != 'e' \
				&& mapber->mapbuff[y][x] != 'd')
			{
				ft_free();
				ft_printexit("ERROR; map mun mai mandatory -kwai- ");
			}
			x++;
		}
		x = 0;
		y++;
	}
}

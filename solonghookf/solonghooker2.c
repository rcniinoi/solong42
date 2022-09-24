/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solonghooker2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:58:39 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 23:05:42 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../solong.h"

int	ft_movecondition(int *move)
{
	if (g_mapber.mapbuff[move[0]][move[1]] == 'Z' \
		|| g_mapber.mapbuff[move[0]][move[1]] == 'Y' \
		|| g_mapber.mapbuff[move[0]][move[1]] == 'W' \
		|| g_mapber.mapbuff[move[0]][move[1]] == 'X')
		return (1);
	else
		return (0);
}

int	ft_movecondition2(int *move)
{
	if (g_mapber.mapbuff[move[0]][move[1]] == 'c' \
		|| g_mapber.mapbuff[move[0]][move[1]] == 'd' \
		|| g_mapber.mapbuff[move[0]][move[1]] == 'e')
		return (1);
	else
		return (0);
}

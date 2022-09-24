/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:24:53 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/23 03:51:36 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "solong.h"

void	ft_putpic(void *mlx)
{
	g_sp.naam = ft_ftoi(mlx, "./sprites/naam32.xpm");
	g_sp.naamhalf = ft_ftoi(mlx, "./sprites/naamhalf32.xpm");
	g_sp.hinyai = ft_ftoi(mlx, "./sprites/hinyai.xpm");
	g_sp.ruabon = ft_ftoi(mlx, "./sprites/ruabon.xpm");
	g_sp.rualang = ft_ftoi(mlx, "./sprites/rualang.xpm");
	g_sp.rualeft = ft_ftoi(mlx, "./sprites/rualeft.xpm");
	g_sp.ruakwa = ft_ftoi(mlx, "./sprites/ruakwa.xpm");
	g_sp.hintun = ft_ftoi(mlx, "./sprites/hintun32.xpm");
	g_sp.redup = ft_ftoi(mlx, "./sprites/red32up.xpm");
	g_sp.reddown = ft_ftoi(mlx, "./sprites/red32down.xpm");
	g_sp.yellowup = ft_ftoi(mlx, "./sprites/yellow32up.xpm");
	g_sp.yellowdown = ft_ftoi(mlx, "./sprites/yellow32down.xpm");
	g_sp.violetup = ft_ftoi(mlx, "./sprites/violet32up.xpm");
	g_sp.violetdown = ft_ftoi(mlx, "./sprites/violet32down.xpm");
	g_sp.wfall = ft_ftoi(mlx, "./sprites/wfall.xpm");
	g_sp.cthulhu = ft_ftoi(mlx, "./sprites/cthulhu.xpm");
	g_sp.hastur = ft_ftoi(mlx, "./sprites/hastur.xpm");
	g_sp.death = ft_ftoi(mlx, "./sprites/death.xpm");
	g_sp.plamuk = ft_ftoi(mlx, "./sprites/plamuk.xpm");
}

void	*ft_ftoi(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	void	*image;

	image = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	return (image);
}

int	ft_itow(void *mlx, char *imgvar)
{
	return (mlx_put_image_to_window(mlx, g_tmlx.mlx_win, imgvar \
		, g_xy.blockx, g_xy.blocky));
}

void	ft_solongini(void)
{
	g_xy.blockx = 0;
	g_xy.blocky = 0;
	g_block = 32;
	g_xy.y = 0;
	g_xy.x = 0;
}

void	ft_free(void)
{
	int	i;

	i = 0;
	while (g_mapber.mapbuff[i])
		free(g_mapber.mapbuff[i++]);
	free (g_mapber.mapbuff);
	g_mapber.mapbuff = NULL;
	if (g_plamuk)
		free (g_plamuk);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:22:35 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/24 21:30:46 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "solong.h"

int	main(int argc, char **argv)
{
	int		count;

	g_count = 0;
	g_frt.fruit = 0;
	g_direction = 13;
	g_buffer.starty = 0;
	g_buffer.startx = 0;
	if (argc != 2)
		ft_printexit("agument I choose you!!!!!");
	ft_getmap(argv[1], &g_mapber);
	ft_xyfinder(&g_mapber);
	ft_wallchkall(&g_mapber, argv[1]);
	ft_mandamap(&g_mapber);
	g_tmlx.mlx = mlx_init();
	g_tmlx.mlx_win = mlx_new_window(g_tmlx.mlx, ((g_mapber.xmax + 1) * 32) \
		, ((g_mapber.ymax +1) * 32), "So_long");
	count = ft_wchk(&g_mapber);
	g_plamuk = malloc(sizeof(t_start) * (count));
	ft_putpic(g_tmlx.mlx);
	ft_output(&g_mapber, 13);
	mlx_hook(g_tmlx.mlx_win, 17, 1L << 0, mlx_close, NULL);
	mlx_hook(g_tmlx.mlx_win, 2, 1L << 0, key_hooker, &g_tmlx);
	mlx_loop_hook(g_tmlx.mlx, key_looper, &g_tmlx);
	mlx_loop(g_tmlx.mlx);
}

int	ft_linecount(char *filename)
{
	int		openfd;
	char	*wainiigon;
	int		count;

	openfd = open(filename, O_RDONLY);
	wainiigon = get_next_line(openfd);
	count = 0;
	while (wainiigon != NULL)
	{
		count++;
		free (wainiigon);
		wainiigon = get_next_line(openfd);
	}
	close(openfd);
	free (wainiigon);
	return (count);
}

void	ft_getmap(char *argv, t_map *g_mapber)
{
	int	openfd;
	int	i;
	int	lcount;

	i = 0;
	lcount = ft_linecount(argv);
	g_mapber->mapbuff = malloc(sizeof(char *) * (lcount + 1));
	openfd = open(argv, O_RDWR);
	if (openfd < 0)
	{
		ft_printf("!!!mai mee map nee!!!\n");
		free(g_mapber->mapbuff);
		exit(0);
	}
	g_mapber->mapbuff[i] = get_next_line(openfd);
	while (g_mapber->mapbuff[i] != NULL)
	{
		i++;
		g_mapber->mapbuff[i] = get_next_line(openfd);
	}
	close(openfd);
}

void	ft_xyfinder(t_map *g_mapber)
{
	int	i;

	g_mapber->xmax = 0;
	g_mapber->ymax = 0;
	i = 0;
	while (g_mapber->mapbuff[0][i] != '\n' && g_mapber->mapbuff[0][i] != '\0')
		g_mapber->xmax = i++;
	i = 0;
	while (g_mapber->mapbuff[i] != NULL )
		g_mapber->ymax = i++;
}

void	ft_output(t_map *mapber, int direction)
{
	ft_putground(mapber);
	ft_showmap(mapber);
	ft_showship(mapber, direction);
	ft_showexit(mapber);
	ft_showfruit(mapber);
	ft_showcthulhu(g_tmlx.mlx);
	ft_showhastur(g_tmlx.mlx);
	ft_showdeath(g_tmlx.mlx);
	ft_showplamuk(g_tmlx.mlx);
}

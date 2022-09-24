/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:01:37 by rchiewli          #+#    #+#             */
/*   Updated: 2022/09/24 03:32:19 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "mlx/mlx.h"
# include "gnlpush/get_next_line.h"
# include "ft_pf/ft_printf.h"
# include <time.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		g_block;
int		g_count;
int		g_direction;

// this is main mlx struct//
typedef struct s_program
{
	void	*mlx;
	void	*mlx_win;
}	t_pro;

// this is map buffer struct //
typedef struct s_map
{
	char	**mapbuff;
	int		xmax;
	int		ymax;
}	t_map;

// this keep starting P position //
typedef struct s_start
{
	int	starty;
	int	startx;
}	t_start;

// this organize xy block 32bit //
typedef struct s_xy
{
	int	blocky;
	int	blockx;
	int	x;
	int	y;
}	t_xyco;

// this keep sprite var //
typedef struct s_sprite
{
	void	*hinyai;
	void	*yaa;
	void	*naam;
	void	*naamhalf;
	void	*ruabon;
	void	*rualang;
	void	*rualeft;
	void	*ruakwa;
	void	*hintun;
	void	*redup;
	void	*reddown;
	void	*yellowup;
	void	*yellowdown;
	void	*violetup;
	void	*violetdown;
	void	*wfall;
	void	*cthulhu;
	void	*hastur;
	void	*death;
	void	*plamuk;
}	t_spr;

// fruit count //
typedef struct s_frtc
{
	int		fruit;
	int		ccount;
}	t_frtc;

t_start	*g_plamuk;
t_start	g_xpo;
t_start	g_ypo;
t_start	g_zpo;
t_start	g_startpo;
t_start	g_buffer;
t_xyco	g_xy;
t_map	g_mapber;
t_pro	g_tmlx;
t_spr	g_sp;
t_frtc	g_frt;

void		ft_getmap(char *argv, t_map *g_mapber);
int			ft_linecount(char *filepath);
void		ft_showmap(t_map *g_mapber);
void		ft_putground(t_map *mapber);
void		ft_xyfinder(t_map *mapber);
void		ft_wallchkall(t_map *mapber, char *argv);
int			ft_wallchk(t_map *mapber, int y, int x, int mode);
int			ft_cchk(t_map *mapber);
int			ft_echk(t_map *mapber);
int			ft_pchk(t_map *mapber);
char		**ft_gettmpmap(char *argv);
t_start		ft_startpo(t_map *mapber);
void		ft_fontoknuk(char *argv, t_map *mapber);
int			ft_flood(char **tmpmap, int y, int x);
char		*ft_strchr(char *s, int c);
void		ft_putstr(char *s);
void		ft_solongini(void);
void		ft_output(t_map *mapber, int direction);
void		ft_showcursedfruit(void *mlx, void *mlx_win, t_map *mapber);
int			key_hooker(int keycode);
void		ft_gogo(int keycode);
int			key_looper(void);
void		*ft_ftoi(void *mlx, char *path);
int			ft_mapmove(int direction);
void		ft_blocknl(void);
void		ft_putpic(void *mlx);
void		ft_showship(t_map *g_mapber, int direction);
void		ft_showexit(t_map *g_mapber);
int			ft_itow(void *mlx, char *imgvar);
void		ft_itowcep(void *mlx, char *imgvar, char *imgvar2);
void		ft_showfruit(t_map *g_mapber);
int			mlx_close(void *ptr);
void		ft_go(int direction);
int			ft_maiok(char *c);
void		ft_showcthulhu(void *mlx);
void		ft_zgo(void);
int			*movechieng(int move[2], int r);
void		ft_showhastur(void *mlx);
t_start		ft_ypo(t_map *mapber);
int			*ft_ymoveposition(void);
void		ft_ygo(void);
void		ft_showdeath(void *mlx);
t_start		ft_xpo(t_map *mapber);
int			*ft_xmoveposition(int r);
void		ft_xgo(void);
void		ft_showplamuk(void *mlx);
t_start		ft_wpo(t_map *mapber);
int			*ft_wmoveposition(int i);
void		ft_plamukini(t_map *mapber);
int			ft_wchk(t_map *mapber);
void		ft_wgo(void);
int			ft_mvchk(int *move);
void		ft_free(void);
int			ft_fillchk(char po);
int			ft_movecondition(int *move);
int			ft_movecondition2(int *move);
void		ft_diefreeexit(int *move);
void		ft_printexit(char *str);
void		ft_mandamap(t_map *mapber);

#endif

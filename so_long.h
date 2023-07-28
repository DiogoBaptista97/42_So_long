/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:10 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/23 16:03:21 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stddef.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define TILES_SIZE 64

typedef struct map
{
	char		**map;
	int			linhas;
	int			colunas;
	int			np;
	int			nc;
	int			ne;
	int			ng;
	int			startx;
	int			starty;
	int			collect;
	int			open;
	int			step;
	int			exit_x;
	int			exit_y;
	int			checked;
}	t_map;

typedef struct mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
}	t_mlx;

typedef struct maptile
{
	void	*img;
}	t_maptile;

typedef struct images
{
	int		idle;
	int		frames;
	void	*imageplayer;
	void	*imageplayeridle2;
	void	*imageexit;
	void	*imageexityes;
	void	*imagecollectable;
	void	*imagepatrol;
	void	*imagefloor;
	void	*imagewall;
	void	*idleanimation;
}	t_images;

typedef struct src
{
	struct map		map;
	struct mlx		mlx;
	struct images	images;
	struct maptile	**tilemap;

	int				x;
	int				y;
	int				steps;
}				t_src;

void	nulltile(t_src *src);
void	errormsg(char *str);
size_t	getlinhas(char	*file);
void	faz_map(char *file, t_src *src);
size_t	getcolunas(char *file);
void	checkretan(t_map *map);
void	check_map(t_src *src);
void	caminho(t_src *src, int x, int y, int **path);
void	checkwall(t_map *map);
void	checktopandbot(t_map *map);
void	checkleftandright(t_map *map);
void	maptileimages(t_src *src);
void	destroyallimages(t_src *src);
void	printmapimages(t_src *src);
void	movementplayer(t_src *src);
void	movementplayer_aux(t_src *src, int i, int j);
int		animation(t_src *src);
int		closeprogram(t_src	*src);
void	movementenemie(t_src *src);
void	movementenemie_aux(t_src *src, int i, int j);
void	enemiecolission(t_src *src, int i, int j);
void	initenemip(t_src *src, int i, int j);
void	newmap(t_src *src);
void	mapimages(t_src *src);
int		contact(t_src *src, int i, int j, int m);
void	populate(t_src *src, size_t enemies, size_t max_tries);
void	checkpe(t_src *src);
void	reconstuct(t_src *src);
int		notmove(t_src *src, int i, int j, int m);
void	refresh(t_src *src);
void	renderimages(t_src *src);
void	printmapimages(t_src *src);
void	variaveis(t_src *src);
void	*colocatile(char c, t_src *src);
void	msg_lost(t_src *src);

#endif

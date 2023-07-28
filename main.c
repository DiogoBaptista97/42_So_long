/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:09:42 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/23 16:09:43 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "./mlx/mlx.h"

void	mexeranimation(t_src *src)
{
	void	*atual;

	if (src->images.idle == 0)
	{
		atual = src->images.imageplayer;
		src->images.idle = 1;
	}
	else
	{
		atual = src->images.imageplayeridle2;
		src->images.idle = 0;
	}
	mlx_put_image_to_window(src->mlx.mlx_ptr,
		src->mlx.window_ptr, atual,
		TILES_SIZE * src->map.starty, TILES_SIZE * src->map.startx);
}

int	animation(t_src *src)
{
	static int	frames;
	char		*linha;

	if (++frames < 10000)
		return (0);
	frames = 0;
	mlx_clear_window(src->mlx.mlx_ptr, src->mlx.window_ptr);
	refresh(src);
	mexeranimation(src);
	linha = ft_itoa(src->map.step);
	mlx_string_put(src->mlx.mlx_ptr, src->mlx.window_ptr,
		50, 50, -1, linha);
	free(linha);
	return (0);
}

int	key_press(int keycode, t_src *src)
{
	src->x = 0;
	src->y = 0;
	if (keycode == 65307)
		mlx_loop_end(src->mlx.mlx_ptr);
	if (keycode == 65361 || keycode == 97)
	{
		src->y = -1;
		movementplayer(src);
	}
	if (keycode == 65362 || keycode == 119)
	{
		src->x = -1;
		movementplayer(src);
	}
	if (keycode == 65363 || keycode == 100)
	{
		src->y = 1;
		movementplayer(src);
	}
	if (keycode == 65364 || keycode == 115)
	{
		src->x = 1;
		movementplayer(src);
	}
	return (0);
}

void	inputs(t_src *src)
{
	mlx_loop_hook(src->mlx.mlx_ptr, animation, src);
	mlx_hook(src->mlx.window_ptr, 2, 1, key_press, src);
	mlx_hook(src->mlx.window_ptr, 17, (2L << 1), closeprogram, src);
}

int	main(int argc, char *argv[])
{
	t_src		src;

	if (argc != 2)
		errormsg("nao existe argc");
	faz_map(argv[1], &src);
	src.mlx.mlx_ptr = mlx_init();
	check_map(&src);
	src.mlx.window_ptr = mlx_new_window(src.mlx.mlx_ptr,
			TILES_SIZE * src.map.colunas,
			TILES_SIZE * src.map.linhas, "so_long");
	maptileimages(&src);
	inputs(&src);
	mlx_loop(src.mlx.mlx_ptr);
	nulltile(&src);
	destroyallimages(&src);
	mlx_destroy_window(src.mlx.mlx_ptr, src.mlx.window_ptr);
	mlx_destroy_display(src.mlx.mlx_ptr);
	free(src.mlx.mlx_ptr);
	return (0);
}

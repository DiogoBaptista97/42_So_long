/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:17:45 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/12/28 14:17:46 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "./mlx/mlx.h"
#include <time.h>

void	destroyallimages(t_src *src)
{
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imagecollectable);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imageexit);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imagefloor);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imagepatrol);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imageplayer);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imagewall);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imageplayeridle2);
	mlx_destroy_image(src->mlx.mlx_ptr, src->images.imageexityes);
}

void	nulltile(t_src *src)
{
	int	i;

	i = -1;
	while (++i < src->map.linhas)
		free(src->tilemap[i]);
	free(src->tilemap);
	i = -1;
	while (++i < src->map.linhas)
		free(src->map.map[i]);
	free (src->map.map);
}

void	goalandmove(t_src *src, int i, int j)
{
	if (src->map.map[src->x + i][src->y + j] == '1')
		return ;
	if (src->map.map[src->x + i][src->y + j] == 'C')
	{
		src->map.nc--;
		if (src->map.nc == 0)
			src->map.open = 1;
	}
	src->map.map[src->x + i][src->y + j] = 'P';
	src->map.map[i][j] = '0';
	src->map.step++;
	src->map.startx = (src->x + i);
	src->map.starty = (src->y + j);
}

void	movementplayer(t_src *src)
{
	int	i;
	int	j;
	int	found;

	movementenemie(src);
	refresh(src);
	found = 0;
	i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			if (src->map.map[i][j] == 'P')
			{
				movementplayer_aux(src, i, j);
				found = 1;
				break ;
			}
		}
		if (found == 1)
			break ;
	}
	refresh(src);
}

void	movementplayer_aux(t_src *src, int i, int j)
{
	if (src->map.map[src->x + i][src->y + j] == '1')
		return ;
	if (src->map.map[src->x + i][src->y + j] == 'E'
			&& src->map.open == 0)
		return ;
	else if (src->map.map[src->x + i][src->y + j] == 'E'
			&& src->map.open == 1)
	{
		ft_printf("NICE!! Well Done, you Win\n");
		closeprogram(src);
	}
	if (src->map.map[src->x + i][src->y + j] == 'G'
		|| src->map.map[i][j] == 'G')
	{
		msg_lost(src);
	}
	goalandmove(src, i, j);
}

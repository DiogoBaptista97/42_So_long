/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fazmapimages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:05:30 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/29 11:05:30 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	*colocatile(char c, t_src *src)
{
	if (c == '1')
		return (src->images.imagewall);
	else if (c == 'C')
		return (src->images.imagecollectable);
	else if (c == 'E' && src->map.open == 0)
		return (src->images.imageexit);
	else if (c == 'E' && src->map.open == 1)
		return (src->images.imageexityes);
	else if (c == 'G')
		return (src->images.imagepatrol);
	else if (c == 'P')
		return (src->images.imageplayer);
	else
		return (src->images.imagefloor);
}

void	mapimages(t_src *src)
{
	int		i;
	int		j;

	src->tilemap = malloc(sizeof(t_maptile *) * src->map.linhas + 1);
	if (!src->tilemap)
		errormsg("Cant do the Tilearray");
	i = -1;
	while (++i < src->map.linhas)
	{
		src->tilemap[i] = malloc(sizeof(t_maptile) * src->map.colunas + 1);
		if (!src->tilemap[i])
			errormsg("Cant make the line of the Tilearray");
		j = -1;
		while (++j < src->map.colunas)
		{
			src->tilemap[i][j].img = colocatile(src->map.map[i][j], src);
		}
	}
}

void	iniciaimages(t_src *src)
{
	int	i;

	i = 50;
	src->images.imagecollectable = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/collectable.xpm", &i, &i);
	src->images.imageexit = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/exit.xpm", &i, &i);
	src->images.imageexityes = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/exityes.xpm", &i, &i);
	src->images.imageplayer = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/player.xpm", &i, &i);
	src->images.imageplayeridle2 = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/playeridle.xpm", &i, &i);
	src->images.imagepatrol = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/patrol.xpm", &i, &i);
	src->images.imagefloor = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/floor.xpm", &i, &i);
	src->images.imagewall = mlx_xpm_file_to_image(
			src->mlx.mlx_ptr, "./images/wall.xpm", &i, &i);
	src->images.idle = 0;
}

void	refresh(t_src *src)
{
	renderimages(src);
	printmapimages(src);
}

void	maptileimages(t_src *src)
{
	iniciaimages(src);
	mapimages(src);
	printmapimages(src);
}

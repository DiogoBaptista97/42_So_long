/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fazmapimages_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:44:34 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/05 19:44:35 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	renderimages(t_src *src)
{
	int	i;
	int	j;

		i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			src->tilemap[i][j].img = colocatile(src->map.map[i][j], src);
		}
	}
}

void	printmapimages(t_src *src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			mlx_put_image_to_window(src->mlx.mlx_ptr,
				src->mlx.window_ptr, src->tilemap[i][j].img,
				TILES_SIZE * j, TILES_SIZE * i);
		}
	}
}

void	variaveis(t_src *src)
{
	src->map.nc = 0;
	src->map.np = 0;
	src->map.ne = 0;
	src->map.collect = 0;
	src->images.frames = 0;
}

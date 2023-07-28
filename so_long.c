/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:06 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/23 16:03:07 by dbraga-b         ###   ########.fr       */
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

void	movementenemie(t_src *src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			if (src->map.map[i][j] == 'G')
			{
				movementenemie_aux(src, i, j);
				if (src->map.map[i][j + 1] == 'G')
						j += 1;
			}
		}
	}
	reconstuct(src);
}

void	reconstuct(t_src *src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			if (src->tilemap[i][j].img == src->images.imagepatrol)
				src->map.map[i][j] = 'G';
		}
	}
}

void	movementenemie_aux(t_src *src, int i, int j)
{
	size_t	m;

	m = rand () % (3 + 1);
	if (m == 0 && src->map.map[i + 1][j] == '0'
		&& src->tilemap[i + 1][j].img != src->images.imagepatrol)
		src->tilemap[i + 1][j].img = src->images.imagepatrol;
	else if (m == 1 && src->map.map[i - 1][j] == '0'
		&& src->tilemap[i - 1][j].img != src->images.imagepatrol)
		src->tilemap[i - 1][j].img = src->images.imagepatrol;
	else if (m == 2 && src->map.map[i][j + 1] == '0'
		&& src->tilemap[i][j + 1].img != src->images.imagepatrol)
		src->tilemap[i][j + 1].img = src->images.imagepatrol;
	else if (m == 3 && src->map.map[i][j - 1] == '0'
		&& src->tilemap[i][j - 1].img != src->images.imagepatrol)
		src->tilemap[i][j - 1].img = src->images.imagepatrol;
	else if ((contact(src, i, j, m)) == 1)
	{
		msg_lost(src);
	}
	else
		return ;
	src->map.map[i][j] = '0';
	src->tilemap[i][j].img = src->images.imagefloor;
}

int	contact(t_src *src, int i, int j, int m)
{
	if (m == 0 && src->map.map[i + 1][j] == 'P')
		return (1);
	else if (m == 1 && src->map.map[i - 1][j] == 'P')
		return (1);
	else if (m == 2 && src->map.map[i][j + 1] == 'P')
		return (1);
	else if (m == 3 && src->map.map[i][j - 1] == 'P')
		return (1);
	else
		return (0);
}

int	closeprogram(t_src	*src)
{
	mlx_loop_end(src->mlx.mlx_ptr);
	return (0);
}

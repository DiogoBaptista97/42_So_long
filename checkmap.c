/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:00:18 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/25 12:00:20 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	finalcheck(t_src *src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			if (src->map.map[i][j] != 'P' && src->map.map[i][j] != 'E' &&
					src->map.map[i][j] != '1' && src->map.map[i][j] != '0' &&
					src->map.map[i][j] != 'C' && (src->map.map[i][j] == 'G'
					|| src->map.checked == 1))
				errormsg("Map invalid due to characters");
			if (src->map.map[i][j] == 'E')
				src->map.ne++;
		}
	}
	if (src->map.ne != 1)
		errormsg("Number of exists invalid");
	src->map.ne = 0;
	src->map.checked = 0;
}

void	iniciar(t_src *src)
{
	int	i;
	int	j;

	variaveis(src);
	i = -1;
	while (++i < src->map.linhas)
	{
		j = -1;
		while (++j < src->map.colunas)
		{
			if (src->map.map[i][j] == 'P')
			{
				src->map.np++;
				src->map.startx = i;
				src->map.starty = j;
			}
			else if (src->map.map[i][j] == 'C')
				src->map.nc++;
		}
	}
	if (src->map.nc == 0)
		errormsg("No collectables");
	finalcheck(src);
}

void	checkpe(t_src *src)
{
	int	i;
	int	j;
	int	**path;

	i = -1;
	path = (int **)malloc(sizeof(int *) * src->map.linhas);
	if (!path)
		errormsg("Memorry alloc array error");
	while (++i < src->map.linhas)
	{
		path[i] = (int *)malloc(sizeof(int) * src->map.colunas);
		if (!path[i])
			errormsg("Memorry alloc string error");
		j = -1;
		while (++j < src->map.colunas)
			path[i][j] = 0;
	}
	caminho(src, src->map.startx, src->map.starty, path);
	i = -1;
	while (++i < src->map.linhas)
		free(path[i]);
	free(path);
}

void	caminho(t_src *src, int x, int y, int **path)
{
	if (src->map.map[x][y] == 'C' && path[x][y] != 1)
		src->map.collect++;
	else if (src->map.map[x][y] == 'E' && path[x][y] != 1)
	{
		src->map.ne++;
		src->map.exit_x = x;
		src->map.exit_y = y;
		path[x][y] = 1;
	}
	else if (src->map.map[x][y] == 'G' && path[x][y] != '1')
	{
		src->map.ng++;
		return ;
	}
	if (path[x][y] == 1)
		return ;
	if (!(x >= 0 && x < src->map.linhas && y >= 0 && y < src->map.colunas
			&& src->map.map[x][y] != '1'))
		return ;
	path[x][y] = 1;
	caminho(src, (x + 1), y, path);
	caminho(src, (x - 1), y, path);
	caminho(src, x, (y + 1), path);
	caminho(src, x, (y - 1), path);
	return ;
}

void	check_map(t_src *src)
{
	iniciar(src);
	checkretan(&src->map);
	checkwall(&src->map);
	checkpe(src);
	if (src->map.collect != src->map.nc)
		errormsg("Can't reach collectables or exit");
	if (src->map.ne != 1 || src->map.np != 1)
		errormsg("Invalid number of player or exit");
	src->map.open = 0;
	src->map.step = 0;
	populate(src, 5, 200);
}

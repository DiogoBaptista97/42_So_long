/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:00:37 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/28 11:00:38 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	checkretan(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->linhas)
	{
		if ((int)ft_strlen(map->map[i]) != map->colunas)
			errormsg("Is not a rectangle");
	}
}

void	checktopandbot(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1')
			errormsg("Problem on the top wall");
		i++;
	}
	i = 0;
	while (map->map[map->linhas - 1][i])
	{
		if (map->map[map->linhas - 1][i] != '1')
			errormsg("Problem on the bottem wall");
		i++;
	}
}

void	checkleftandright(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->linhas)
	{
		if (map->map[i][0] != '1')
			errormsg("Problem on the left wall");
	}
	i = -1;
	while (++i < map->linhas)
	{
		if (map->map[i][map->colunas - 1] != '1')
			errormsg("Problem on the right wall");
	}
}

void	populate(t_src *src, size_t enemies, size_t max_tries)
{
	size_t	i;
	size_t	j;

	i = rand () % src->map.linhas;
	j = rand () % src->map.colunas;
	if (enemies == 0 || max_tries == 0)
		return ;
	if (src->map.map[i][j] != '0')
		populate(src, enemies, max_tries - 1);
	if (src->map.map[i][j] == '0')
	{
		src->map.map[i][j] = 'G';
		src->map.collect = 0;
		src->map.ne = 0;
		src->map.np = 0;
		checkpe(src);
		if (src->map.collect != src->map.nc || src->map.ne != 1)
		{
			src->map.map[i][j] = '0';
			populate(src, enemies, max_tries -1);
		}
		else
			populate(src, enemies - 1, max_tries -1);
	}
}

void	checkwall(t_map *map)
{
	checktopandbot(map);
	checkleftandright(map);
}

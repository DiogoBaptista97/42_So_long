/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fazmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:32:29 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/28 11:32:48 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	errormsg(char *str)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	msg_lost(t_src *src)
{
	ft_printf("You lost\n");
	closeprogram(src);
}

size_t	getlinhas(char	*file)
{
	int		fd;
	size_t	i;
	char	*ola;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		errormsg("File not open");
	ola = get_next_line(fd);
	while (ola)
	{
		i++;
		free(ola);
		ola = get_next_line(fd);
	}
	free(ola);
	close (fd);
	return (i);
}

void	faz_map(char *file, t_src *src)
{
	char	**arraymap;
	int		i;
	int		fd;
	char	*ola;

	i = -1;
	src->map.linhas = getlinhas(file);
	src->map.map = malloc(src->map.linhas * sizeof(char *));
	arraymap = malloc(src->map.linhas * sizeof(char *));
	fd = open(file, O_RDONLY);
	while (++i < src->map.linhas)
	{
		ola = get_next_line(fd);
		arraymap[i] = ft_strtrim(ola, "\n");
		src->map.map[i] = ft_strdup(arraymap[i]);
		free(arraymap[i]);
		free(ola);
	}
	ola = get_next_line(fd);
	free(ola);
	src->map.colunas = ft_strlen(src->map.map[0]);
	free(arraymap);
	close(fd);
	src->map.checked = 1;
}

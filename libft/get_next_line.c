/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:14:46 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/16 12:48:57 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h"
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

char	*ft_getline(char *stash)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	if (!stash[i])
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*cleanstash(char *stash)
{
	int		start;
	int		i;
	char	*new;

	i = 0;
	start = 0;
	while (stash[start] != '\n' && stash[start])
		start++;
	if (!stash[start])
	{
		free(stash);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(stash) - start) + 1);
	if (!new)
		return (NULL);
	start++;
	while (stash[start])
		new[i++] = stash[start++];
	new[i] = 0;
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	stash = stashsize(fd, stash);
	if (!stash)
		return (NULL);
	str = ft_getline(stash);
	stash = cleanstash(stash);
	return (str);
}
/* 
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("texto.txt", O_RDONLY);
	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd1);
		printf("line [%02d]:%s: \n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
} */

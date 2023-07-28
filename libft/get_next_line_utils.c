/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:26:46 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/16 12:48:58 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h"
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

char	*ft_strjoinget(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*ptr;
	int		i;
	int		h;

	h = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[h])
		ptr[i++] = s2[h++];
	ptr[i] = '\0';
	free ((void *)s1);
	return (ptr);
}

char	*ft_strchrget(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		else
			i++;
	}
	if (ptr[i] == c)
		return (&ptr[i]);
	return (NULL);
}

char	*stashsize(int fd, char *stash)
{
	char	*buffer;
	int		bufferread;

	bufferread = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		return (NULL);
	}
	while (bufferread > 0)
	{
		bufferread = read(fd, buffer, BUFFER_SIZE);
		if (bufferread == -1 || (bufferread == 0 && buffer == NULL))
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bufferread] = 0;
		stash = ft_strjoinget(stash, buffer);
		if (ft_strchrget(stash, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

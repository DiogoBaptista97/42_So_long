/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:49:00 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:53 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (len);
	while (src[i] != 0 && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
#include<bsd/string.h>
#include<stdio.h>
int	main(void)
{
	const char		src[] = "HelloWordl";
	char		dest[] = "Tiago";
	size_t i;

	i = strlcpy(dest, src, 4);
	printf("%zu\n", i);

	return (0);
}*/

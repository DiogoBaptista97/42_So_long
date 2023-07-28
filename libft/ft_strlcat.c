/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:20:30 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:54 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	d;
	int		i;
	size_t	max;

	l = ft_strlen(src);
	i = 0;
	if (!dst && size == 0)
		return (l);
	d = ft_strlen(dst);
	max = ft_strlen(dst);
	if (size <= d)
		return (l + size);
	while (src[i] != '\0' && (d < (size - 1)))
	{
		dst[d] = src[i];
		d++;
		i++;
	}
	dst[d] = '\0';
	return (max + l);
}
/*
int	main(void)
{
	int			i;
	char		dst[40];
	const char	*src;

	src = "Ti";
	i = ft_strlcat(dst, src, 3);
	i = i;
	//printf("%d\n", i);
	return (0);
}*/

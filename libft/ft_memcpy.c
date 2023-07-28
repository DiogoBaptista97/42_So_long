/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:10:37 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:19 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptrdest;
	char	*ptrsrc;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
/* 
#include<string.h>
#include<stdio.h>
int	main(void)
{
	char *src = "Helloword";
	char dest[2];
	char *srcs = "Helloword";
	char dests[2];
	printf("%s\n", (char *)ft_memcpy(dest, src, 5));
	printf("%s\n", (char *)memcpy(dests, srcs, 5));
} */

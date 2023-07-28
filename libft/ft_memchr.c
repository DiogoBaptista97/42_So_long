/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:48:58 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:22 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	i = 0;
	ptrs = (unsigned char *)s;
	while (n-- > 0)
	{
		if (ptrs[i] == (unsigned char)c)
		{
			return (ptrs + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	const char	str[] = "HELLO";
	char	*ret;
	
	ret = ft_memchr(str, 'T', ft_strlen(str));
	printf("%s \n", ret);
	return (0);
}*/

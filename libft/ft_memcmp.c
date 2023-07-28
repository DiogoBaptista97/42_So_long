/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:09:37 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:21 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	int					value;
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	ptrs1 = (const unsigned char *)s1;
	ptrs2 = (const unsigned char *)s2;
	value = 0;
	i = 0;
	while (i < n)
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (value);
}
/* 
#include<string.h>
int	main(void)
{
	int	i;
	char	str1[] = "HeLLO";
	char	str2[] = "HELLO";
	
	printf("%d\n", memcmp(str1, str2, 5));
	printf("%d\n", ft_memcmp(str1, str2, 2));
} */

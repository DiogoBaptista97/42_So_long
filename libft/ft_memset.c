/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:34:59 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:18 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (n != 0)
	{
		ptr[i] = (char) c;
		n--;
		i++;
	}
	return (s);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[] = "Hello";
 	printf("%s\n", ft_memset(str, 65, 2));
 	printf("%s\n", memset(str, 65, 2));
}*/

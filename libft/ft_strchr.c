/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:00:35 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:06 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

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
/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	char	str[] = "HELLO";
	printf("%s\n", ft_strchr(str, 'P'));
	return (0);
}*/

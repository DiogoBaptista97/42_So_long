/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:27:49 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:48 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}	
/*
#include<string.h>
#include<stdio.h>
int	main(void)
{
	char str[] = "Hello";
	printf("%lu\n", ft_strlen(str));
	printf("%lu\n", strlen(str));
}
*/

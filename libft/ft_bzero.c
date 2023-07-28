/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:43:30 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:03:03 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (n != 0)
	{
		ptr[i] = '\0';
		n--;
		i++;
	}
}
/*
#include<stdio.h>
int main(void)
{
	char str[] = "Hello wordls asdad";
	char caos[] = "Hello wordls asdad";
	ft_bzero(&str[4], 1);
	bzero(&caos[4], 1);
 	printf("%s\n", str);
 	printf("%s\n", caos);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:22:06 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:19 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*newsrc;
	char	*newdest;
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	newdest = (char *)dest;
	newsrc = (char *)src;
	if (newdest > newsrc)
	{
		while (n != 0)
		{
			n--;
			newdest[n] = newsrc[n];
		}
	}
	else if (newsrc > newdest)
	{
		while (++i < n)
			newdest[i] = newsrc[i];
	}
	return (newdest);
}
/*
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int	main(void)
{
  char	strs[] = "memmove can be very useful......";
  ft_memmove (strs+20,strs+15,11);
  puts (strs);
  char str[] = "memmove can be very useful......";
  memmove (str+20,str+15,11);
  puts (str);
  return 0;
}
*/

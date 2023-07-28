/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:17:42 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/15 15:43:21 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"
#include<stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	size_t			i;
	unsigned int	j;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	j = nmemb * size;
	while (j > 0)
	{
		ptr[i] = 0;
		i++;
		j--;
	}
	return ((void *)ptr);
}
/*

#include<stdlib.h>
int main(void)
{

}*/

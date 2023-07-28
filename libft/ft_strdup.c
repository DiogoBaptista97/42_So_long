/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:51:39 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:05 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		n;

	i = ft_strlen(s);
	ptr = malloc(sizeof(char) * (i + 1));
	n = 0;
	if (!ptr)
		return (NULL);
	while (n < i)
	{
		ptr[n] = s[n];
		n++;
	}
	ptr[n] = 0;
	return (ptr);
}

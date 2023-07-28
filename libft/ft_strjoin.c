/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:34:55 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:55 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*ptr;
	int		i;
	int		h;

	h = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[h])
		ptr[i++] = s2[h++];
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char const	s1[] = "Hello";
	char const	s2[] = "World";

	printf("%s\n", ft_strjoin(s1, s2));
}*/

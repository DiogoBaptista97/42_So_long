/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:05:53 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:42 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	truel;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		str = malloc (sizeof(char) * 1);
		str[0] = 0;
		return (str);
	}
	truel = ft_strlen(&s[start]);
	if (truel < len)
		len = truel;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len-- > 0)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
/* 
#include<stdio.h>
int	main(void)
{
	char	*str = "Hello Cruel world";

	printf("%s\n", ft_substr(str, 6, 5));
} */

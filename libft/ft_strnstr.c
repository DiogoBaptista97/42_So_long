/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:41:43 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:45 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if ((!little || !big) && len == 0)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] != 0 && little[j] != 0
			&& big[i + j] == little [j] && (i + j) < len)
		{
			if (little[j + 1] == 0)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	haystack[] = "DiogoMiguelTiago";
	const char	needle[] = "Miguel";
	const char	*ret;
	const char	ft_haystack[] = "DiogoMiguelTiago";
	const char	ft_needle[] = "Miguel";
	const char	*ft_ret;

	ft_ret = ft_strnstr(ft_haystack, ft_needle, 20);
	printf("%s \n", ft_ret);
}*/

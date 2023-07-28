/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:57:05 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:43 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		f;
	char		*ptr;
	int			tamanho;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && (ft_strchr(set, s1[i]) != 0))
		i++;
	f = ft_strlen(s1);
	while (f > i && (ft_strchr(set, s1[f - 1]) != 0))
		f--;
	tamanho = f - i;
	ptr = malloc(sizeof(char) * (tamanho + 1));
	if (!ptr)
		return (NULL);
	f = 0;
	while (tamanho-- > 0)
		ptr[f++] = s1[i++];
	ptr[f] = 0;
	return (ptr);
}
/* 
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
#include<stdio.h>

int	main(void)
{
	char const	s1[] = "DIOGOTIAGOMIGUELDIOGO";
	char const	set[] = "IODGO";
	char	*str;
	int		l;

	str = ft_strtrim(s1, set);
	printf(":%s:\n", str);
} */

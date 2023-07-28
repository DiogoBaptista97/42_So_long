/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:35:45 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:44 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	*last;

	i = 0;
	last = NULL;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == c)
			last = &ptr[i];
		i++;
	}
	if (ptr[i] == c)
		return (&ptr[i]);
	return (last);
}
/*
int	main(void)
{
	const char	str[] = "Hello";

	printf("%s\n", ft_strrchr(str, 'e'));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:07:30 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:03:03 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(char *str)
{
	int	j;
	int	sinal;
	int	res;

	sinal = 1;
	res = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if ((*str == '-' || *str == '+') && (*str))
	{
		if (*str == '-')
		{
			sinal = sinal * (-1);
		}
		if (*str != '-' && *str != '+')
			return (0);
		str++;
	}
	j = 0;
	while ((str[j] >= '0' && str[j] <= '9') && str[j] != 0)
	{	
		res = (res * 10) + (str[j] - '0');
		j++;
	}
	return (res * sinal);
}
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{

	char	str[] = "	-+-+--+-23hghgh  ";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}
*/

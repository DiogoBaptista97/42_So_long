/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:54:34 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/21 17:54:35 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

long	osize(long n)
{
	long	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

int	ft_longitoa(long int n)
{
	int		len;
	char	*str;
	int		i;

	len = osize(n);
	i = len;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	len--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	else if (n == 0)
		str[len] = '0';
	while (n != 0)
	{
		str[len--] = (n % 10) + 48;
		n = n / 10;
	}
	ft_putstr_fd(str, 1);
	free (str);
	return (i);
}

int	ft_printdecimal(va_list args, int tamanho)
{
	long int		i;

	i = va_arg(args, int);
	tamanho += ft_longitoa(i);
	return (tamanho);
}

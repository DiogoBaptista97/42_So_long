/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:16:19 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/18 18:14:44 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	calls(const char c, va_list	args, int tamanho)
{
	if (c == 'c')
		tamanho = ft_printchar(args, tamanho);
	else if (c == 's')
		tamanho = ft_printstr(args, tamanho);
	else if (c == 'p')
		tamanho = ft_printaddr(args, tamanho);
	else if (c == 'd' || c == 'i')
		tamanho = ft_printdecimal(args, tamanho);
	else if (c == 'u')
		tamanho = ft_printunsig(args, tamanho);
	else if (c == 'x')
		tamanho = ft_printlowerx(args, tamanho);
	else if (c == 'X')
		tamanho = ft_printupperx(args, tamanho);
	else if (c == '%')
	{
		write(1, "%", 1);
		tamanho++;
	}
	return (tamanho);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		tamanho;
	int		i;

	va_start(args, format);
	tamanho = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tamanho = calls(format[i + 1], args, tamanho);
			i++;
			i++;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			tamanho++;
			i++;
		}
	}
	va_end(args);
	return (tamanho);
}
/* 
int	main(void)
{
	int		i;
	int			j;
	char		*ptri;
	int			*ptrj;

	i = printf("NULL %X NULL", 169);
	printf("\n");
	printf("o tamanho edele>%d \n", i);
	printf("\n");
	j = ft_printf("NULL %X NULL", 169);
	printf("\n");
	printf("o tamanho eomeu>%d \n", j);
}*/

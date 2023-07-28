/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:43:06 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/18 18:28:17 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

size_t	osize16(unsigned long n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		l = 1;
	while (n != 0)
	{
		n = n / 16;
		l++;
	}
	return (l);
}

void	ft_putnubhex_fd(unsigned long addr, int fd)
{
	if (addr >= 16)
	{
		ft_putnubhex_fd(addr / 16, fd);
		ft_putnubhex_fd(addr % 16, fd);
	}
	else
	{
		if (addr < 10)
			ft_putchar_fd (addr + 48, 1);
		else
			ft_putchar_fd (addr - 10 + 'a', 1);
	}
}

int	ft_printaddr(va_list args, int tamanho)
{
	void	*addr;

	addr = va_arg(args, void *);
	if (!addr)
	{
		tamanho += write(1, "(nil)", 5);
		return (tamanho);
	}
	write(1, "0x", 2);
	tamanho += 2;
	ft_putnubhex_fd((unsigned long)addr, 1);
	tamanho += osize16((unsigned long)addr);
	return (tamanho);
}

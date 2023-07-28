/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowerx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:32:46 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/21 19:32:47 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	ft_printlowerx(va_list args, int tamanho)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	if (c == 0)
	{
		write (1, "0", 1);
		return (tamanho + 1);
	}
	ft_putnubhex_fd((unsigned long)c, 1);
	tamanho += osize16((unsigned long)c);
	return (tamanho);
}

void	ft_putnubhexup_fd(unsigned long addr, int fd)
{
	if (addr >= 16)
	{
		ft_putnubhexup_fd(addr / 16, fd);
		ft_putnubhexup_fd(addr % 16, fd);
	}
	else
	{
		if (addr < 10)
			ft_putchar_fd (addr + 48, 1);
		else
			ft_putchar_fd (addr - 10 + 'A', 1);
	}
}

int	ft_printupperx(va_list args, int tamanho)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	if (c == 0)
	{
		write (1, "0", 1);
		return (tamanho + 1);
	}
	ft_putnubhexup_fd((unsigned long)c, 1);
	tamanho += osize16((unsigned long)c);
	return (tamanho);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:57:09 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/21 17:57:10 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	ft_printunsig(va_list args, int tamanho)
{
	long int		i;

	i = va_arg(args, unsigned int);
	tamanho += ft_longitoa(i);
	return (tamanho);
}

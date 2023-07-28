/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:27:30 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:03:01 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("%d\n", ft_isalpha('c'));
	printf("%d\n", isalpha('d'));
	printf("%d\n", isalpha('D'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('1'));
}*/

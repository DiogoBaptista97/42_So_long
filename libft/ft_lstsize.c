/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:59 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:22 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include<stdio.h>
#include<stdlib.h>

int		main()
{
	t_list *head;
	t_list *last;

	t_list *dois;
	t_list *tres;

	Definir as structs

	if (!(head = malloc(sizeof(t_list))))
		return 0; comentario Estes aqui são 0 porque estás n
		o MAIN e é um -> Int <-. Logo é 0.

	head->content = "Um";
	head->next = NULL;

	if (!(dois = malloc(sizeof(t_list))))
		return 0;

	dois->content = "Dois";
	dois->next = NULL;

	if (!(tres = malloc(sizeof(t_list))))
		return 0;

	tres->content = "Tres";
	tres->next = NULL;

	Meter o Last como o primeiro e indo avançar até chegar ao último

	last = head;

	while (last->next != NULL)
		last = last->next;
	last->next = dois;

	last = head;

	while (last->next != NULL)
		last = last->next;
	last->next = tres;

	printf("%s -- %s -- %s -- %p\n", 
				(char *)head->content, (char *)head->next->content,
				 (char *)head->next->next->content, head->next->next->next);

	printf("%d", ft_lstsize(head));

}*/

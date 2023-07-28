/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:06 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/15 15:53:14 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

void	ft_lstadd_front(t_list	**lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* 
#include<stdio.h>
#include"libft.h"
#include<stdlib.h>

int	main(void)
{
	t_list	*head;
	t_list *new;

	if(!(head = malloc(sizeof(t_list))))
		return (0);
	head->content = (char *)"olah";
	head->next = NULL;
	if(!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = (char *)"adeus";
	new->next = NULL;
	printf("Head -> %s\n", (char *)head->content);
	ft_lstadd_front(&head, new);
	printf("Head -> %s\n", (char *)head->content);
} */

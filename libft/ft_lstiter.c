/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:53:55 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:52 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
int	main(void)
{
	t_list	*head;
	t_list	*um;
	t_list	*dois;
	t_list	*tres;

	char c1[] = "-- Adeus Um --";
	char c2[] = "-- Adeus Dois --";
	char c3[] = "-- Adeus Tres --";
	char c4[] = "-- Adeus Quatro --";

	head = ft_lstnew(c1);
	um = ft_lstnew(c2);
	dois = ft_lstnew(c3);
	tres = ft_lstnew(c4);

	ft_lstadd_back(&head, um);
	ft_lstadd_back(&head, dois);
	ft_lstadd_back(&head, tres);

	int size;
	size = ft_lstsize(head);
	t_list *start;
	start = head;

	for(int i = 0; i < size; i++)
	{
		printf("%s", (char *)head->content);
		head = head->next;
	}

	head = start;

	ft_lstiter(head, f);
	printf("\n");

	for(int i = 0; i < size; i++)
	{
		printf("%s", (char *)head->content);
		head = head->next;
	}


	return (0);
} */

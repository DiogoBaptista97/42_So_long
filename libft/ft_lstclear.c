/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <dbraga-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:39:47 by dbraga-b          #+#    #+#             */
/*   Updated: 2022/11/15 15:53:27 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

/* nao consegui desenvolver a main direita, 
	core dump problems da main
#include<stdio.h>
#include"libft.h"
#include<stdlib.h>
void	del(void *este)
{
 	free (este);
}

int		main()
{
	t_list *head;
	t_list *dois;
	t_list *tres;
	t_list *quatro;

	char c1[] = "um--";
    char c2[] = "Dois --";
    char c3[] = "Tres --";
    char c4[] = "Quatro --";

	head = ft_lstnew(c1);
	dois = ft_lstnew(c2);
	tres = ft_lstnew(c3);
	quatro = ft_lstnew(c4);

	ft_lstadd_back(&head, dois);
	ft_lstadd_back(&head, tres);
	ft_lstadd_back(&head, quatro);

	printf("\n%s	    %s	%s	    %s\n", (char *)head->content, 
										(char *)head->next->content,
										(char *)head->next->next->content,
										(char *)head->next->next->next->content);
	printf("%p %p %p %p %p\n", head, head->next, head->next->next, 
									head->next->next->next,
									head->next->next->next->next);
	
	ft_lstclear(&head, del);

	printf("\n%p\n", head);

	return (0);
} */

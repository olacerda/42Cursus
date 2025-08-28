/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:04:36 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/29 02:12:11 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*nexttemp;

	temp = *lst;
	while (temp != NULL)
	{
		nexttemp = temp->next;
		del(temp->content);
		free(temp);
		temp = nexttemp;
	}
	*lst = NULL;
}

// static void	del(void *content)
// {
// 	if (!content)
// 		return ;
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*node1 = ft_lstnew(ft_strdup("Node1"));
// 	t_list	*node2 = ft_lstnew(ft_strdup("Node2"));
// 	t_list	*node3 = ft_lstnew(ft_strdup("Node3"));
// 	t_list	*node4 = ft_lstnew(ft_strdup("Node4"));
	
// 	t_list	*head = node1;
// 	t_list	*head2 = node1;

// 	ft_lstadd_back(&head, node2); // Adds the nodes
// 	ft_lstadd_back(&head, node3); // Adds the nodes
// 	ft_lstadd_back(&head, node4); // Adds the nodes
	
// 	while (head != NULL)
// 	{
// 		printf("Before: %s\n", (char *)head->content);
// 		head = head->next;
// 	}
// 	printf("\n");
	
// 	ft_lstclear(&node3, del); // lstclear's the list on "Node3"
		
// 	while (head2 != NULL)
// 	{
// 		printf("After: %s\n", (char *)head2->content);
// 		head2 = head2->next;
// 	}
// }
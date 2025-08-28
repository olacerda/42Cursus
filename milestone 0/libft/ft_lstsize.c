/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:32:37 by otlacerd          #+#    #+#             */
/*   Updated: 2025/05/28 19:14:45 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	int	count;

	count = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	*node1 = ft_lstnew("node1");
// 	t_list	*node2 = ft_lstnew("node2");
// 	t_list	*head = node2;
// 	int	size;

// 	size = ft_lstsize(head);
// 	printf("Before: %d\n", size);

	
// 	ft_lstadd_front(&head, node1);
// 	size = ft_lstsize(node1);
// 	printf("After: %d\n", size);
// }
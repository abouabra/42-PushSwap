/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_stuff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:15:20 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 18:47:14 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last_node(t_node *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	add_node_in_back(t_node **head, t_node *node)
{
	t_node	*tmp;

	if (*head)
	{
		tmp = ft_last_node(*head);
		tmp->next = node;
	}
	else
		*head = node;
}

void	add_node_in_front(t_node **head, t_node *node)
{
	if (*head && node)
		node->next = *head;
	if (node)
		*head = node;
}

t_node	*ft_new_node(int data)
{
	t_node	*node;
	int		x;
	int		y;

	x = 0;
	y = 0;
	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_node_clear(t_node **head)
{
	t_node	*tmp;

	if (head != NULL)
	{
		while (*head != NULL)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
		*head = NULL;
	}
}

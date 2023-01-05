/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_stuff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:15:20 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 17:33:50 by abouabra         ###   ########.fr       */
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
	if(node)
		*head = node;
}

t_node	*ft_new_node(int data)
{
	t_node	*node;
	int			x;
	int			y;

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

int	ft_node_size(t_node **head)
{
	t_node	*tmp;
	int i;

	i=0;
	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}

void print_list(t_args *vars)
{
	t_node *tmp_a;
	t_node *tmp_b;
	
	tmp_a = vars->a_head;
	tmp_b = vars->b_head;
	ft_dprintf(1, "STACK A\n");
	while(tmp_a)
	{
		ft_dprintf(1, "DATA: %d  INDEX: %d\n",tmp_a->data,tmp_a->index);
		tmp_a = tmp_a->next;
	}
	ft_dprintf(1, "\n");
	ft_dprintf(1, "STACK B\n");
	while(tmp_b)
	{
		ft_dprintf(1, "DATA: %d  INDEX: %d\n",tmp_b->data,tmp_b->index);
		tmp_b = tmp_b->next;
	}
	ft_dprintf(1, "\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:31:57 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 10:48:29 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_args *vars, int is_print)
{
	t_node	*last_element;
	t_node	*before_last;

	if (!vars->a_head)
		return ;
	last_element = ft_last_node(vars->a_head);
	before_last = vars->a_head;
	while (before_last->next != last_element)
		before_last = before_last->next;
	before_last->next = NULL;
	add_node_in_front(&vars->a_head, last_element);
	if (is_print)
		ft_dprintf(1, "rra\n");
}

void	rrb(t_args *vars, int is_print)
{
	t_node	*last_element;
	t_node	*before_last;

	if (!vars->b_head)
		return ;
	last_element = ft_last_node(vars->b_head);
	before_last = vars->b_head;
	while (before_last->next != last_element)
		before_last = before_last->next;
	before_last->next = NULL;
	add_node_in_front(&vars->b_head, last_element);
	if (is_print)
		ft_dprintf(1, "rrb\n");
}

void	rrr(t_args *vars, int is_print)
{
	if (!vars->b_head || !vars->a_head)
		return ;
	rra(vars, 0);
	rrb(vars, 0);
	if (is_print)
		ft_dprintf(1, "rrr\n");
}

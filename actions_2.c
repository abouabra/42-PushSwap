/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:31:57 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/13 15:27:32 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_args *vars, int is_print)
{
	t_node	*first_element;
	t_node	*last_element;
	t_node	*second_element;

	if (!vars->a_head || ft_node_size(&vars->a_head) <= 1)
		return ;
	first_element = vars->a_head;
	second_element = first_element->next;
	vars->a_head = second_element;
	last_element = ft_last_node(vars->a_head);
	last_element->next = first_element;
	first_element->next = NULL;
	if (is_print)
		ft_dprintf(1, "ra\n");
}

void	rb(t_args *vars, int is_print)
{
	t_node	*first_element;
	t_node	*last_element;
	t_node	*second_element;

	if (!vars->b_head || ft_node_size(&vars->b_head) <= 1)
		return ;
	first_element = vars->b_head;
	second_element = first_element->next;
	vars->b_head = second_element;
	last_element = ft_last_node(vars->b_head);
	last_element->next = first_element;
	first_element->next = NULL;
	if (is_print)
		ft_dprintf(1, "rb\n");
}

void	rr(t_args *vars, int is_print)
{
	if (!vars->b_head || !vars->a_head || ft_node_size(&vars->b_head) <= 1
		|| ft_node_size(&vars->a_head) <= 1)
		return ;
	ra(vars, 0);
	rb(vars, 0);
	if (is_print)
		ft_dprintf(1, "rr\n");
}

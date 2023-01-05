/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:31:57 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 15:57:29 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_dprintf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	sa(t_args *vars, int is_print)
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*third_element;

	if (!vars->a_head)
		return ;
	first_element = vars->a_head;
	second_element = first_element->next;
	third_element = second_element->next;
	vars->a_head = second_element;
	second_element->next = first_element;
	first_element->next = third_element;
	if (is_print)
		ft_dprintf(1, "sa\n");
}

void	sb(t_args *vars, int is_print)
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*third_element;

	if (!vars->b_head)
		return ;
	first_element = vars->b_head;
	second_element = first_element->next;
	third_element = second_element->next;
	vars->b_head = second_element;
	second_element->next = first_element;
	first_element->next = third_element;
	if (is_print)
		ft_dprintf(1, "sb\n");
}

void	ss(t_args *vars, int is_print)
{
	if (!vars->b_head || !vars->a_head)
		return ;
	sa(vars, 0);
	sb(vars, 0);
	if (is_print)
		ft_dprintf(1, "ss\n");
}

void	pa(t_args *vars, int is_print)
{
	t_node	*first_element_in_b;

	if (!vars->b_head)
		return ;
	first_element_in_b = vars->b_head;
	vars->b_head = first_element_in_b->next;
	first_element_in_b->next = NULL;
	add_node_in_front(&vars->a_head, first_element_in_b);
	if (is_print)
		ft_dprintf(1, "pa\n");
}

void	pb(t_args *vars, int is_print)
{
	t_node	*first_element_in_a;

	if (!vars->a_head)
		return ;
	first_element_in_a = vars->a_head;
	vars->a_head = first_element_in_a->next;
	first_element_in_a->next = NULL;
	add_node_in_front(&vars->b_head, first_element_in_a);
	if (is_print)
		ft_dprintf(1, "pb\n");
}

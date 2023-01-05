/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:34:39 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 18:45:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_all_numbers_to_b(t_args *vars, int range)
{
	t_node	*node;
	int		i;

	i = 0;
	node = vars->a_head;
	while (node)
	{
		if (node->index <= i && i > 1)
		{
			pb(vars, 1);
			rb(vars, 1);
			i++;
		}
		else if (node->index <= i + range)
		{
			pb(vars, 1);
			i++;
		}
		else
			ra(vars, 1);
		node = vars->a_head;
	}
}

void	sort_big_numbers(t_args *vars, int range)
{
	t_node	*node;

	send_all_numbers_to_b(vars, range);
	node = vars->b_head;
	while (node)
	{
		while (!top_is_biggest(vars))
			make_move_in_chunk(vars);
		pa(vars, 1);
		node = vars->b_head;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:34:39 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 17:36:56 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_big_numbers(t_args *vars,int range)
{
	int i;
	t_node *node;
	
	i = 0;
	node = vars->a_head;
	while(node)
	{
		if(node->index <= i && i > 1)
		{
			pb(vars,1);
			rb(vars,1);
			i++;
		}
		else if(node->index <= i + range)
		{
			pb(vars,1);
			i++;
		}
		else
			ra(vars,1);
		node = vars->a_head;
	}
	node = vars->b_head;
	while(node)
	{
		send_biggest_to_top(vars);
		pa(vars,1);
		node = vars->b_head;
	}
}

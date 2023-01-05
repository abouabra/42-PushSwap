/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:34:39 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 12:42:00 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_numbers(t_args *vars)
{
	int elem_1;
	int elem_2;
	int elem_3;

	elem_1 = vars->a_head->data;
	elem_2 = vars->a_head->next->data;
	elem_3 = vars->a_head->next->next->data;
	if(elem_1 > elem_2 && elem_2 < elem_3 && elem_1 < elem_3)
		sa(vars,1);
	else if(elem_1 > elem_2 && elem_2 > elem_3 && elem_1 > elem_3)
	{
		sa(vars,1);
		rra(vars,1);
	}
	else if(elem_1 > elem_2 && elem_2 < elem_3 && elem_1 > elem_3)
		ra(vars,1);
	else if(elem_1 < elem_2 && elem_2 > elem_3 && elem_1 < elem_3)
	{
		sa(vars,1);
		ra(vars,1);
	}
	else if(elem_1 < elem_2 && elem_2 > elem_3 && elem_1 > elem_3)
		rra(vars,1);
}
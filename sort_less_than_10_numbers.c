/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_10_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:34:39 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 18:34:53 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_than_10_numbers(t_args *vars)
{
	int	i;

	i = -1;
	while (++i < vars->args_counter - 3)
	{
		while (!top_is_smallest(vars) && !is_shorted(vars))
			make_move(vars);
		pb(vars, 1);
	}
	while (!is_shorted(vars))
		sort_3_numbers(vars);
	i = -1;
	while (++i <= vars->args_counter - 3)
		pa(vars, 1);
}

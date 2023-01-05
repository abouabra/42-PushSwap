/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:53:01 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 17:36:32 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_args *vars;
	
	if(ac < 3)
		return 0;
	vars = ft_calloc(1, sizeof(t_args));
	if(!vars)
		return 0;
	if(!check_args(vars ,ac, av))
		return 0;
	extract_args(vars);
	
	
	if(ac-1 == 2 && !is_shorted(vars))
		sa(vars, 1);
	if(ac-1 == 3 && !is_shorted(vars))
		sort_3_numbers(vars);
	if(ac-1 > 3 && ac-1 <= 10 && !is_shorted(vars))
		sort_less_than_10_numbers(vars);
	
	
	if(ac-1 > 10 && ac-1 <= 100 && !is_shorted(vars))
		sort_big_numbers(vars,15);
	if(ac-1 > 100 && ac-1 <= 500 && !is_shorted(vars))
		sort_big_numbers(vars,30);

	//print_list(vars);
	end_phase(vars);
    return 0;
}
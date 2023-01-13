/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:53:01 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/13 13:07:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_dprintf.h"
#include <stdio.h>

void	short_the_args(t_args	*vars)
{
	//printf("%d\n",vars->args_counter);
	if (vars->args_counter == 2 && !is_shorted(vars))
		sa(vars, 1);
	if (vars->args_counter == 3 && !is_shorted(vars))
		sort_3_numbers(vars);
	if (vars->args_counter > 3 && vars->args_counter <= 10 && !is_shorted(vars))
		sort_less_than_10_numbers(vars);
	if (vars->args_counter > 10 && vars->args_counter <= 100 && !is_shorted(vars))
		sort_big_numbers(vars, 15);
	if (vars->args_counter > 100 && vars->args_counter <= 500 && !is_shorted(vars))
		sort_big_numbers(vars, 30);
	if (vars->args_counter > 500 && !is_shorted(vars))
		sort_big_numbers(vars, 45);
}

int	main(int ac, char **av)
{
	t_args	*vars;

	// if (ac < 2)
	// {
	// 	ft_dprintf(2, "Error\n");
	// 	return (0);
	// }
	vars = ft_calloc(1, sizeof(t_args));
	if (!vars)
		return (0);
	if (!check_args(vars, ac, av))
	{
		end_phase(vars);
		return (0);
	}
	extract_args(vars);
	short_the_args(vars);
	end_phase(vars);
	return (0);
}

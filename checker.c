/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:02:29 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 19:19:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instruction_3(t_args *vars, char *tmp)
{
	if (!ft_strncmp(tmp, "rra\n", -1))
	{
		rra(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rrb\n", -1))
	{
		rrb(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rrr\n", -1))
	{
		rrr(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "pa\n", -1))
	{
		pa(vars, 0);
		return (1);
	}
	return (0);
}

int	check_instruction_2(t_args *vars, char *tmp)
{
	if (!ft_strncmp(tmp, "ra\n", -1))
	{
		ra(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rb\n", -1))
	{
		rb(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rr\n", -1))
	{
		rr(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "pb\n", -1))
	{
		pb(vars, 0);
		return (1);
	}
	if (check_instruction_3(vars, tmp))
		return (1);
	return (0);
}

void	check_instruction(t_args *vars, char *tmp)
{
	if (!ft_strncmp(tmp, "sa\n", -1))
	{
		sa(vars, 0);
		return ;
	}
	if (!ft_strncmp(tmp, "sb\n", -1))
	{
		sb(vars, 0);
		return ;
	}
	if (!ft_strncmp(tmp, "ss\n", -1))
	{
		ss(vars, 0);
		return ;
	}
	if (check_instruction_2(vars, tmp))
		return ;
	ft_dprintf(2, "Error\n");
	free(tmp);
	end_phase(vars);
	exit(0);
}

void	handle_data(t_args *vars)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		check_instruction(vars, tmp);
		if (is_shorted(vars))
			break ;
		free(tmp);
	}
	free(tmp);
	if (is_shorted(vars))
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
}

int	main(int ac, char **av)
{
	t_args	*vars;

	if (ac < 2)
		return (0);
	vars = ft_calloc(1, sizeof(t_args));
	if (!vars)
		return (0);
	if (!check_args(vars, ac, av))
	{
		end_phase(vars);
		return (0);
	}
	extract_args(vars);
	if (is_shorted(vars))
	{
		ft_dprintf(1, "OK\n");
		end_phase(vars);
		return (0);
	}
	handle_data(vars);
	end_phase(vars);
	return (0);
}

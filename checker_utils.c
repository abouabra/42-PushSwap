/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:02:29 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/13 16:30:41 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instruction_4(t_args *vars, char *tmp, int i)
{
	if (!ft_strncmp(tmp, "pb", -1) || !ft_strncmp(tmp, "pb\n", -1))
	{
		if (i)
			pb(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "pa", -1) || !ft_strncmp(tmp, "pa\n", -1))
	{
		if (i)
			pa(vars, 0);
		return (1);
	}
	return (0);
}

int	check_instruction_3(t_args *vars, char *tmp, int i)
{
	if (!ft_strncmp(tmp, "rra", -1) || !ft_strncmp(tmp, "rra\n", -1))
	{
		if (i)
			rra(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rrb", -1) || !ft_strncmp(tmp, "rrb\n", -1))
	{
		if (i)
			rrb(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rrr", -1) || !ft_strncmp(tmp, "rrr\n", -1))
	{
		if (i)
			rrr(vars, 0);
		return (1);
	}
	if (check_instruction_4(vars, tmp, i))
		return (1);
	return (0);
}

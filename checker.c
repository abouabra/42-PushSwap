/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:02:29 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/13 16:29:45 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instruction_2(t_args *vars, char *tmp, int i)
{
	if (!ft_strncmp(tmp, "ra", -1) || !ft_strncmp(tmp, "ra\n", -1))
	{
		if (i)
			ra(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rb", -1) || !ft_strncmp(tmp, "rb\n", -1))
	{
		if (i)
			rb(vars, 0);
		return (1);
	}
	if (!ft_strncmp(tmp, "rr", -1) || !ft_strncmp(tmp, "rr\n", -1))
	{
		if (i)
			rr(vars, 0);
		return (1);
	}
	if (check_instruction_3(vars, tmp, i))
		return (1);
	return (0);
}

void	check_instruction(t_args *vars, char *tmp, int i)
{
	if (!ft_strncmp(tmp, "sa", -1) || !ft_strncmp(tmp, "sa\n", -1))
	{
		if (i)
			sa(vars, 0);
		return ;
	}
	if (!ft_strncmp(tmp, "sb", -1) || !ft_strncmp(tmp, "sb\n", -1))
	{
		if (i)
			sb(vars, 0);
		return ;
	}
	if (!ft_strncmp(tmp, "ss", -1) || !ft_strncmp(tmp, "ss\n", -1))
	{
		if (i)
			ss(vars, 0);
		return ;
	}
	if (check_instruction_2(vars, tmp, i))
		return ;
	ft_dprintf(2, "Error\n");
	if (i)
		free_char_array(vars->instructions_bonus);
	end_phase(vars);
	exit(0);
}

void	process_data(t_args *vars, char *final)
{
	int	i;

	if (!final)
		return ;
	vars->instructions_bonus = ft_split(final, '\n');
	i = -1;
	while (vars->instructions_bonus[++i])
		check_instruction(vars, vars->instructions_bonus[i], 1);
	free_char_array(vars->instructions_bonus);
	free(final);
}

void	handle_data(t_args *vars)
{
	char	*tmp;
	char	*final;

	final = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		check_instruction(vars, tmp, 0);
		final = ft_strjoin_gnl(final, tmp);
		free(tmp);
	}
	free(tmp);
	process_data(vars, final);
	if (is_shorted(vars) && ft_node_size(&vars->b_head) == 0)
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
	handle_data(vars);
	end_phase(vars);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:31:38 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/13 12:51:57 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extract_tmp_arr_2(char **tmp, int j, int *x, long *final)
{
	if (!ft_atol(tmp[j]) && !ft_is_number(tmp[j]))
	{
		ft_dprintf(2, "Error\n");
		free_char_array(tmp);
		free(final);
		return (0);
	}
	final[*x] = ft_atol(tmp[j]);
	(*x)++;
	return (1);
}

long	*extract_tmp_arr(t_args *vars, int ac, char **av)
{
	long	*final;
	char	**tmp;
	int		i;
	int		x;
	int		j;

	final = ft_calloc(1, vars->args_counter * sizeof(long));
	if (!final)
		return (0);
	i = 0;
	x = 0;
	while (++i < ac)
	{
		tmp = ft_split(av[i], ' ');
		j = -1;
		while (tmp[++j])
			if (!extract_tmp_arr_2(tmp, j, &x, final))
				return (0);
		free_char_array(tmp);
	}
	return (final);
}

int	check_is_duplicated_num(t_args *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->args_counter)
	{
		j = i;
		while (++j < vars->args_counter)
		{
			if (vars->tmp_arr[i] == vars->tmp_arr[j])
			{
				ft_dprintf(2, "Error\n");
				return (0);
			}
		}
		if (vars->tmp_arr[i] > INT_MAX || vars->tmp_arr[i] < INT_MIN)
		{
			ft_dprintf(2, "Error\n");
			return (0);
		}
	}
	return (1);
}
int	check_args(t_args *vars, int ac, char **av)
{
	vars->args_counter = count_args(av);
	if (vars->args_counter == -1)
	{
		ft_dprintf(2, "Error\n");
		return (0);
	}
	vars->tmp_arr = extract_tmp_arr(vars, ac, av);
	if (!vars->tmp_arr)
		return (0);
	if (!check_is_duplicated_num(vars))
		return (0);
	return (1);
}

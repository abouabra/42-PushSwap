/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:31:38 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 11:58:35 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	count_args(char **av)
{
	int		i;
	int		j;
	int		x;
	char	**tmp;

	i = 0;
	x = 0;
	while (av[++i])
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp[0] || !tmp)
			return (-1);
		j = -1;
		while (tmp[++j])
			x++;
		free_char_array(tmp);
	}
	return (x);
}

void	free_char_array(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

int is_shorted(t_args *vars)
{
	t_node *i;
	t_node *j;
	
	i = vars->a_head;
	while(i)
	{
		j = i->next;
		if(j && j->data < i->data)
			return 0;
		i = i->next;
	}
	return 1;	
}

void	end_phase(t_args *vars)
{
	ft_node_clear(&vars->a_head);
	ft_node_clear(&vars->b_head);
	free(vars->tmp_arr);
	free(vars);
}
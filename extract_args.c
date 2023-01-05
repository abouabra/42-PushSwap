/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:15:20 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 15:59:11 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long *sort_arr(t_args *vars)
{
	int i;
	int j;
	long *final;
	long tmp;

	final = ft_calloc(1, vars->args_counter*sizeof(long));
	if(!final)
		return 0;
	i=-1;
	while(++i < vars->args_counter)
		final[i] = vars->tmp_arr[i];
	i=-1;
	while(++i < vars->args_counter)
	{
		j=-1;
		while(++j < vars->args_counter)
		{
			if(final[j] > final[i])
			{
				tmp = final[i];
				final[i] = final[j];
				final[j] = tmp;
			}
		}
	}
	return final;
}

void fill_with_sorted_array(t_args *vars)
{
	t_node *node;
	int i;

	i = -1;
	node = vars->a_head;
	while(node)
	{
		i = -1;
		while(++i <vars->args_counter)
			if(node->data == vars->sorted_arr[i])
				node->index = i;
		node = node->next;
	}
}

void extract_args(t_args *vars)
{
	t_node *tmp;
	int i;
	
	vars->a_head = NULL;
	i=-1;
	while(++i < vars->args_counter)
	{
		tmp = ft_new_node(vars->tmp_arr[i]);
		add_node_in_back(&vars->a_head,tmp);
	}
	vars->sorted_arr = sort_arr(vars);
	fill_with_sorted_array(vars);
}
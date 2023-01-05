/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:22:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 14:43:02 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int top_is_smallest(t_args *vars)
{
	int tmp;
	t_node *node;

	node = vars->a_head;
	tmp = node->data;
	while(node)
	{
		if(tmp > node->data)
			return 0;
		node = node->next;
	}
	return 1;
}

int get_smallest_node_data(t_args *vars)
{
	t_node *node;
	int data;
	
	node = vars->a_head;
	data = node->data;
	while(node)
	{
		if(node->data < data)
			data = node->data;
		node = node->next;
	}
	return data;
}

int get_smallest_index(t_args *vars)
{
	t_node *node;
	int data;
	int i;

	i=0;
	data = get_smallest_node_data(vars);
	node = vars->a_head;
	while(node)
	{
		if(node->data == data)
			break;
		i++;
		node = node->next;
	}
	return i;
}

int determin_move(t_args *vars)
{
	int index;
	int i;

	i = vars->args_counter -1;
	index = get_smallest_index(vars);
	if(i/2 >= index)
		return 1;
	if(i/2 < index)
		return 2;
	return 0;
}

void make_move(t_args *vars)
{
	int move;
	
	move = determin_move(vars);
	if(!move)
		return;
	if(move == 1)
		ra(vars,1);
	if(move == 2)
		rra(vars,1);
}
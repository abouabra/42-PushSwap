/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:22:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 17:33:43 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int top_is_biggest(t_args *vars)
{
	int tmp;
	t_node *node;

	node = vars->b_head;
	tmp = node->data;
	while(node)
	{
		if(tmp < node->data)
			return 0;
		node = node->next;
	}
	return 1;
}

int find_biggest_node_data(t_args *vars)
{
	t_node *node;
	int data;
	
	node = vars->b_head;
	data = node->data;
	while(node)
	{
		if(node->data > data)
			data = node->data;
		node = node->next;
	}
	return data;
}

int get_biggest_node_index(t_args *vars)
{
	t_node *node;
	int data;
	int i;

	i=0;
	data = find_biggest_node_data(vars);
	node = vars->b_head;
	while(node)
	{
		if(node->data == data)
			break;
		i++;
		node = node->next;
	}
	return i;
}

int determin_move_in_chunck(t_args *vars)
{
	int index;
	int i;

	i = ft_node_size(&vars->b_head) -1;
	index = get_biggest_node_index(vars);
	if(i/2 >= index)
		return 1;
	if(i/2 < index)
		return 2;
	return 0;
}

void make_move_in_chunk(t_args *vars)
{
	int move;
	
	move = determin_move_in_chunck(vars);
	if(!move)
		return;
	if(move == 1)
		rb(vars,1);
	if(move == 2)
		rrb(vars,1);
}

void send_biggest_to_top(t_args *vars)
{
	while(!top_is_biggest(vars))
		make_move_in_chunk(vars);
}
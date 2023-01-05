/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:53:17 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/05 19:07:25 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct t_node
{
	int				data;
	int				index;
	struct t_node	*next;
}					t_node;

typedef struct t_args
{
	long			*tmp_arr;
	long			*sorted_arr;
	int				args_counter;
	t_node			*a_head;
	t_node			*b_head;

}					t_args;

void				sa(t_args *vars, int is_print);
void				sb(t_args *vars, int is_print);
void				ss(t_args *vars, int is_print);

void				ra(t_args *vars, int is_print);
void				rb(t_args *vars, int is_print);
void				rr(t_args *vars, int is_print);

void				rra(t_args *vars, int is_print);
void				rrb(t_args *vars, int is_print);
void				rrr(t_args *vars, int is_print);

void				pb(t_args *vars, int is_print);
void				pa(t_args *vars, int is_print);

int					check_args(t_args *vars, int ac, char **av);
long				ft_atol(char *str);
int					ft_is_number(char *str);
int					count_args(char **av);
void				free_char_array(char **tmp);

void				extract_args(t_args *vars);
t_node				*ft_new_node(int data);
void				add_node_in_back(t_node **head, t_node *node);
t_node				*ft_last_node(t_node *lst);
void				add_node_in_front(t_node **head, t_node *node);
void				ft_node_clear(t_node **head);
int					is_shorted(t_args *vars);
void				end_phase(t_args *vars);
void				sort_3_numbers(t_args *vars);
void				sort_less_than_10_numbers(t_args *vars);
int					top_is_smallest(t_args *vars);
int					get_smallest_index(t_args *vars);
int					determin_move(t_args *vars);
void				make_move(t_args *vars);
void				sort_big_numbers(t_args *vars, int range);

int					top_is_biggest(t_args *vars);
int					find_biggest_node_data(t_args *vars);
t_node				*get_biggest_node(t_args *vars);
void				send_biggest_to_top(t_args *vars);
int					ft_node_size(t_node **head);
void				make_move_in_chunk(t_args *vars);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koito <koito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:55:21 by koito             #+#    #+#             */
/*   Updated: 2025/12/16 00:48:02 by koito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*before;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
	t_node			*under;
}					t_stack;

typedef struct s_stacks
{
	t_stack		a_stacks;
	t_stack		b_stacks;
}					t_stacks;

//sort
void				sort_2(t_stacks *stacks);
void				sort_3_helper(t_stacks *stacks, int max_position);
void				sort_3(t_stacks *stacks);
void				sort_4_helper(t_stacks *stacks, int min_position);
void				sort_4(t_stacks *stacks);
void				sort_5_helper(t_stacks *stacks, int min_position);
void				sort_5(t_stacks *stacks);
//stack_free_null
void				stacks_in_null(t_stacks *stacks);
void				free_stack_a(t_stack *a);
void				free_stack_b(t_stack *b);
void				free_sp(char **out);
void				free_split_stacks(t_stacks *stacks, char **split_number);
//in_sort_number
void				add_split_num(t_stacks *stacks, char **split_number);
void				in_sort_number(t_stacks *stacks, int argc, char **argv);
//in_sort_number-ft_split_ps
size_t				ft_strlen(const char *s);
size_t				col_malloc_len(char const *s, char c);
char				*ft_strdup_sp(const char *src, char c, size_t i);
char				**resu_sp(t_stacks *st, char **out, char const *s, char c);
char				**ft_split_ps(t_stacks *stacks, char const *s, char c);
//in_sort_number-ft_atoi_check_ps
int					check_minus(char c, int *minus);
bool				error_check_over_number(long int out, char c, int minus);
int					ft_atoi_check(t_stacks *stacks, char *str, char **sp_num);
//in_sort_number_helper
void				check_dup(t_stacks *stacks, int check_value, char **sp_num);
t_node				*node_new(int value);
void				under_add(t_stack *stack, t_node *node);
//execute_sort
unsigned int		value_to_unsigned(int value);
int					max_bit_size(t_stacks *stacks);
void				radix_sort(t_stacks *stacks);
void				execute_sort(t_stacks *stacks);
//ascending_order_check
bool				ascending_order_check(t_stack *a);
//sa
void				sa_ps_size_two(t_stack *a);
void				sa_ps_size_over_two(t_stack *a);
void				sa_ps(t_stacks *stacks);
//sb
void				sb_ps_size_two(t_stack *b);
void				sb_ps_size_over_two(t_stack *b);
void				sb_ps(t_stacks *stacks);
//ss
void				sa_ps_ss(t_stacks *stacks);
void				sb_ps_ss(t_stacks *stacks);
void				ss_ps(t_stacks *stacks);
//pa
void				pa_ps_helper(t_stack *a, t_node *n1);
void				pa_ps(t_stacks *stacks);
//pb
void				pb_ps_helper(t_stack *b, t_node *n1);
void				pb_ps(t_stacks *stacks);
//ra
void				ra_ps(t_stacks *stacks);
//rb
void				rb_ps(t_stacks *stacks);
//rr
void				ra_ps_rr(t_stacks *stacks);
void				rb_ps_rr(t_stacks *stacks);
void				rr_ps(t_stacks *stacks);
//rra
void				rra_ps(t_stacks *stacks);
//rrb
void				rrb_ps(t_stacks *stacks);
//rrr
void				rra_ps_rrr(t_stacks *stacks);
void				rrb_ps_rrr(t_stacks *stacks);
void				rrr_ps(t_stacks *stacks);
//index_stack
void				index_sort(int *index, int a_size);
int					index_search(int *index, int a_size, int value);
void				index_stack(t_stacks *stacks);

#endif

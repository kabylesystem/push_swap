/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:09:23 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:22:06 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	int	keep;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int	size;
}	t_stack;

void	init_stack(t_stack *s);
void	free_stack(t_stack *s);

void	parse(int ac, char **av, t_stack *a);
int		process_tokens(char **tokens, t_stack *a);
int		check_duplicates(t_stack *a);
void	free_split(char **tab);
void	error_exit(void);

char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
int		is_digit(int c);
t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack *a, t_node *new);


void	assign_index(t_stack *a);
void	bubble_sort(int *tab, int size);
void	indexer(t_stack *a, int *tab);

void	lis_main(t_stack *a);
int	*malloc_tab(int size);
void	indextab(t_stack *a, int *tab);
void	compute_lis(int *tab, int *lis, int size);
int	find_the_longest_lis(int *lis, int size);
void	reconstruct_lis(int *lis, int *tab, int *keep, int end);
void	mark_keep_nodes(t_stack *a, int *keep);

void	update_positions(t_stack *s);
int		get_min_pos(t_stack *a);
void	set_target_positions(t_stack *a, t_stack *b);
void	set_moves(t_stack *a, t_stack *b);


t_node	*get_cheapest(t_stack *b);

void	apply_rotations(t_stack *a, t_stack *b, int *ca, int *cb);
void	move_node(t_stack *a, t_stack *b, t_node *nb);
void	insert_all(t_stack *a, t_stack *b);
void	align_a(t_stack *a);

void	push_non_keep_to_B(t_stack *a, t_stack *b);

void	push_swap(t_stack *a, t_stack *b);

int		is_sorted(t_stack *a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

int		do_swap(t_stack *s);
int		do_push(t_stack *dst, t_stack *src);
int		do_rotate(t_stack *s);
int		do_rev_rotate(t_stack *s);
void	put_op(const char *s);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif

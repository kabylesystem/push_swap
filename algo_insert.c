/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:50:02 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 21:39:10 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node(t_stack *a, t_stack *b, t_node *nb)
{
	int	ca;
	int	cb;

	if (!nb)
		return ;
	ca = nb->cost_a;
	cb = nb->cost_b;
	apply_rotations(a, b, &ca, &cb);
	pa(a, b);
}

void	insert_all(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b && b->size > 0)
	{
		update_positions(a);
		update_positions(b);
		set_target_positions(a, b);
		set_moves(a, b);
		cheapest = get_cheapest(b);
		move_node (a, b, cheapest);
	}
}

void	align_a(t_stack *a)
{
	int	min_pos;

	if (!a || a->size < 2)
		return ;
	update_positions(a);
	min_pos = get_min_pos(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			ra(a);		
	}
	else
	{
		min_pos = min_pos - a->size;
		while (min_pos++ < 0)
			rra(a);
	}
}
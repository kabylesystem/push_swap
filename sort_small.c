/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:25:01 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 22:29:25 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	if (!a || a->size < 2)
		return (1);
	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_2(t_stack *a)
{
	if (a && a->size == 2 && a->top->index > a->top->next->index)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->index;
	y = a->top->next->index;
	z = a->top->next->next->index;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	bring_min_to_top(t_stack *a)
{
	int	pos;

	update_positions(a);
	pos = get_min_pos(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = pos - a->size;
		while (pos++ < 0)
			rra(a);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		bring_min_to_top(a);
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
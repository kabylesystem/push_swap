/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:05:42 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:05:43 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		return (max_int(ft_abs(cost_a), ft_abs(cost_b)));
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

t_node *get_cheapest(t_stack *b)
{
	t_node *tmp;
	t_node *cheapest;
	int	best;
	int	cost;
	
	if (!b || !b->top)
		return (NULL);
	tmp = b->top;
	cheapest = NULL;
	best = INT_MAX;
	while (tmp)
	{
		cost = total_cost(tmp->cost_a, tmp->cost_b);
		if (cost < best)
		{
			best = cost;
			cheapest = tmp;
		}
		tmp=tmp->next;
	}
	return (cheapest);
}

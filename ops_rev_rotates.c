/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:47:09 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:07:34 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (do_rev_rotate(a))
		put_op("rra\n");
}

void	rrb(t_stack *b)
{
	if (do_rev_rotate(b))
		put_op("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = do_rev_rotate(a);
	y = do_rev_rotate(b);
	if (x || y)
		put_op("rrr\n");
}
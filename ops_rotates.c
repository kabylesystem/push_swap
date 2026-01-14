/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:47:09 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:07:34 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (do_rotate(a))
		put_op("ra\n");
}

void	rb(t_stack *b)
{
	if (do_rotate(b))
		put_op("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = do_rotate(a);
	y = do_rotate(b);
	if (x || y)
		put_op("rr\n");
}
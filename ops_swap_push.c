/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:47:09 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:07:34 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *a)
{
    if (do_swap(a))
        put_op("sa\n");
}

void   sb(t_stack *b)
{
    if (do_swap(b))
        put_op("sb\n");
}

void    ss(t_stack *a, t_stack *b)
{
    int x;
    int y;

    x = do_swap(a);
    y = do_swap(b);
    if (x || y)
        put_op("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (do_push(a, b))
		put_op("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (do_push(b, a))
		put_op("pb\n");
}
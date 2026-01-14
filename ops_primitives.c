/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:47:09 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:07:34 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_op(const char *s)
{
    while (*s)
        write (1, s++, 1);
}

int do_swap(t_stack *s)
{
    t_node  *a;
    t_node  *b;

    if (!s || s->size < 2)
        return (0);
    a = s->top;
    b = a->next;
    a->next = b->next;
    b->next = a;
    s->top = b;
    return (1);
}

int do_push(t_stack *dst, t_stack *src)
{
    t_node *tmp;

    if (!dst || !src || src->size == 0)
        return (0);
    tmp = src->top;
    src->top = src->top->next;
    src->size--;
    tmp->next = dst->top;
    dst->top = tmp;
    dst->size++;
    return (1);
}

int do_rotate(t_stack *s)
{
    t_node  *first;
    t_node  *last;

    if (!s || s->size < 2)
        return (0);
    first = s->top;
    s->top = first->next;
    first->next = NULL;
    last = s->top;
    while (last->next)
        last = last->next;
    last->next = first;
    return (1);
}

int do_rev_rotate(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	prev = NULL;
	last = s->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = s->top;
	s->top = last;
	return (1);
}
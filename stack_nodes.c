/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:47:09 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:07:34 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node   *ft_lstlast(t_node *n)
{
	while (n && (n->next))
		n = n->next;
	return (n);
}

t_node  *ft_lstnew(int value)
{
	t_node  *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->keep = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack *a, t_node *new)
{
	t_node	*last;

	if (!a || !new)
		return ;
	if (!a->top)
		a->top = new;
	else
	{
		last = ft_lstlast(a->top);
		last->next = new;
	}
	a->size++;
}

void    free_stack(t_stack *s)
{
	t_node  *tmp;

	if (!s)
		return ;
	while (s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
	s->size = 0;
}

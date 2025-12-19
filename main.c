/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:47:09 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:07:34 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	if (!s)
		return ;
	s->top = NULL;
	s->size = 0;
}


int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	parse(ac, av, &a);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

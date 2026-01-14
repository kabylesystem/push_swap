/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:25:01 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 22:29:25 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_non_keep_to_B(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size;
	while(i--)
	{
		if (a->top->keep == 0)
			pb(a, b);
		else
			ra(a);
	}
}
void	sort_big(t_stack *a, t_stack *b)
{
	lis_main(a);
	push_non_keep_to_B(a, b);
	insert_all(a, b);
	align_a(a);
}
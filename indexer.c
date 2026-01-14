/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 03:21:44 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/10 00:50:13 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	int	*tab;
	int	i;
	t_node *tmp;

	tmp = a->top;
	tab = malloc(sizeof(int) * a->size);
	if (!tab)
		return ;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(tab, a->size);
	indexer(a, tab);
	free(tab);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexer(t_stack *a, int *tab)
{	
	t_node *tmp;
	int	i;

	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < a->size)
		{
			if (tab[i] == tmp->value)
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

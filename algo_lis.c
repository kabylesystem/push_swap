/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:50:42 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/16 21:22:13 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*malloc_tab(int size);
void	indextab(t_stack *a, int *tab);
void	compute_lis(int *tab, int *lis, int size);
int	find_the_longest_lis(int *lis, int size);
void	reconstruct_lis(int *lis, int *tab, int *keep, int end);
void	mark_keep_nodes(t_stack *a, int *keep);

void	lis_main(t_stack *a)
{
	int	*tab;
	int	*lis;
	int	*keep;
	int	size;
	int	end;

	size = a->size;
	tab = malloc_tab(size);
	lis = malloc_tab(size);
	keep = malloc_tab(size);
	if (!tab || !lis || !keep)
		return ;
	indextab(a, tab);
	compute_lis(tab, lis, size);
	end = find_the_longest_lis(lis, size);
	reconstruct_lis(lis, tab, keep, end);
	mark_keep_nodes(a, keep);
	free(tab);
	free(lis);
	free(keep);
}

int	*malloc_tab(int size)
{
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	return (tab);
}

void	indextab(t_stack *a, int *tab)
{
	t_node	*tmp;
	int	i;

	tmp = a->top;
	i = 0;
	while(tmp)
	{
		tab[i++] = tmp->index;
		tmp=tmp->next;
	}
}

void	compute_lis(int *tab, int *lis, int size)
{	
	int	i;
	int	j;
	
	i = 0;
	while(i < size)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (tab[j] < tab[i] && lis[j] + 1 > lis[i])
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
}

int	find_the_longest_lis(int *lis, int size)
{
	int	end;
	int	i;

	end = 0;
	i = 1;
	while (i < size)
	{
		if (lis[i] > lis[end])
			end = i;
		i++;
	}
	return (end);
}


void	reconstruct_lis(int *lis, int *tab, int *keep, int end)
{
	int	i;
	int	current_len;
	int	current_val;

	current_len = lis[end];
	current_val = tab[end];
	keep[end] = 1;
	i = end - 1;
	while (i >= 0)
	{
		if (tab[i] < current_val && lis[i] == current_len - 1)
		{
			keep[i] = 1;
			current_val = tab[i];
			current_len = lis[i]; 
		}
		i--;
	}
}

void	mark_keep_nodes(t_stack *a, int *keep)
{
	t_node *tmp;
	int	i;

	i = 0;
	tmp = a->top;
	while(tmp)
	{
		tmp->keep = keep[i];
		tmp = tmp->next;
		i++;
	}
}

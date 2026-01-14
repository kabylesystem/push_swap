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
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
		tab[i++] = 0;
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

static int	binary_search(int *tail, int tail_len, int x)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = tail_len;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (tail[mid] < x)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

void	compute_lis(int *tab, int *lis, int size)
{
	int	*tail;
	int	*parent;
	int	tail_len;
	int	i;
	int	pos;

	tail = malloc(sizeof(int) * size);
	parent = malloc(sizeof(int) * size);
	if (!tail || !parent)
		return ;
	tail_len = 0;
	i = 0;
	while (i < size)
	{
		pos = binary_search(tail, tail_len, tab[i]);
		tail[pos] = tab[i];
		parent[i] = (pos > 0) ? tail[pos - 1] : -1;
		if (pos == tail_len)
			tail_len++;
		lis[i] = pos + 1;
		i++;
	}
	free(tail);
	free(parent);
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
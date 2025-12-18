/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:19:13 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/16 21:22:26 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reconstruct_lis(int *lis, int *tab, int *keep, int end)
{
        int     i;
        int     current_len;
        int     current_val;

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

void    mark_keep_nodes(t_stack *a, int *keep)
{
        t_node *tmp;
        int     i;

        i = 0;
        tmp = a->top;
        while(tmp)
        {
                tmp->keep = keep[i];
                tmp = tmp->next;
                i++;
        }
}

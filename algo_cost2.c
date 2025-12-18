/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:05:42 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 14:07:37 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

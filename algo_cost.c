/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:53:11 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 13:25:18 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	update_positions(t_stack *s)
{
	t_node *tmp;
	int	i;

	tmp = s->top;
	i = 0;
	while(tmp)
	{
		tmp->pos = i;
		tmp=tmp->next;
		i++;
	}
}

void	set_target_positions(t_stack *a, t_stack *b)
{
	t_node *nb;
	t_node *na;
	int	best_index;
	int	target;

	nb = b->top;
	while (nb)
	{
		best_index = INT_MAX;
		na = a->top;
		while (na)
		{
			if (na->index > nb->index && na->index < best_index)
			{
				best_index = na->index;
				target = na->pos;
			}
			na = na->next;
		}
		if (best_index == INT_MAX)
			target = get_min_pos(a);
		nb->target_pos = target;
		nb = nb->next;
	}
}

int	get_min_pos(t_stack *a)
{
	t_node	*tmp;
	int	min_index;
	int	min_pos;

	tmp = a->top;
	min_index = INT_MAX;
	while(tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}	
		tmp = tmp->next;	
	}
	return (min_pos);
}

static int	calc_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	set_moves(t_stack *a, t_stack *b)
{
	t_node	*nb;

	nb = b->top;
	while(nb)
	{
		nb->cost_b = calc_cost(nb->pos, b->size);
		nb->cost_a = calc_cost(nb->target_pos, a->size)
		nb = nb->next;
	}
}

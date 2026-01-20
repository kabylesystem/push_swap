/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:09:23 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/18 23:22:06 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	exec_op(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (do_swap(a), 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (do_swap(b), 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (do_swap(a), do_swap(b), 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (do_push(a, b), 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (do_push(b, a), 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (do_rotate(a), 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (do_rotate(b), 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (do_rotate(a), do_rotate(b), 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (do_rev_rotate(a), 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (do_rev_rotate(b), 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (do_rev_rotate(a), do_rev_rotate(b), 1);
	return (0);
}

static int	read_and_exec(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_op(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static int	is_sorted_checker(t_stack *a)
{
	t_node	*tmp;

	if (!a || a->size < 2)
		return (1);
	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
	if (!read_and_exec(&a, &b))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	if (is_sorted_checker(&a) && b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

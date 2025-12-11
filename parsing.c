/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:56:06 by ynabti            #+#    #+#             */
/*   Updated: 2025/12/10 17:21:47 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(int ac, char **av, t_stack *a)
{
	char	**tokens;
	int	i;

	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!process_tokens(tokens, a))
			error_exit();
		free_split(tokens);
		i++;
	}
	if (!check_duplicates(a))
		error_exit();
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	process_tokens(char **tokens, t_stack *a)
{
	int	i;
	int	j;
	long	nb;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		while (tokens[i][j])
		{
			if (!is_digit(tokens[i][j]) && tokens[i][j] != '-' && tokens[i][j] != '+')
				return (0);
			j++;
		}
		nb = ft_atol(tokens[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		ft_lstadd_back(a, ft_lstnew((int)nb));
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

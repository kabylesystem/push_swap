/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:56:06 by ynabti            #+#    #+#             */
/*   Updated: 2025/11/29 00:24:44 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(int argc, char **argv, t_stack *a)
{
	char	**tokens;
	int	i;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
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
	 int		i;
	int		j;
	long	nb;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		if (!tokens[i][0])
			return (0);
		if ((tokens[i][0] == '-' || tokens[i][0] == '+') && !tokens[i][1])
			return (0);
		if (tokens[i][0] == '-' || tokens[i][0] == '+')
			j = 1;
		while (tokens[i][j] && is_digit(tokens[i][j]))
			j++;
		if (tokens[i][j])
			return (0);
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
	t_node *i = a->top;
	t_node *j;

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

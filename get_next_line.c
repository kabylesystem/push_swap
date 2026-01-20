/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynabti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:32:49 by ynabti            #+#    #+#             */
/*   Updated: 2025/11/27 17:13:26 by ynabti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*buffer_to_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*cut_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = buffer_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		return (stash = NULL, NULL);
	}
	stash = cut_stash(stash);
	return (line);
}

static char	*buffer_to_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		n;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	n = 1;
	while (!gnl_strchr(stash, '\n') && n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(buffer), free(stash), NULL);
		if (n == 0)
			break ;
		buffer[n] = '\0';
		tmp = gnl_strjoin(stash, buffer);
		if (!tmp)
			return (free(buffer), free(stash), NULL);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*res;
	int		i;

	if (!stash[0] || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	res = malloc(i + (stash[i] == '\n') + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

static char	*cut_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = gnl_strdup(stash + i + 1);
	if (!new_stash)
		return (free(stash), NULL);
	free(stash);
	return (new_stash);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:18:54 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/21 17:21:35 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, char **stash)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !stash)
		return (NULL);
	if (!ft_stash(fd, stash))
		return (NULL);
	line = extract_line(*stash);
	if (!line)
		return (NULL);
	*stash = trim_stash(*stash);
	return (line);
}

static int	ft_stash(int fd, char **stash)
{
	char		*buf[BUFFER_SIZE + 1];
	ssize_t		bytes;

	if (!stash)
		return (0);
	bytes = 1;
	while (!gnl_strchr(*stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (0);
		if (!*stash)
		{
			*stash = malloc(1);
			if (!*stash)
				return (0);
			(*stash)[0] = '\0';
		}
		*stash = gnl_strjoin(*stash, buf);
		if (!*stash)
			return (0);
	}
	return (1);
}

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

#include "../libft.h"
#include "get_next_line.h"

static int	ft_stash(int fd, char **stash);


char	*get_next_line(int fd)
{
	char		*line;
	static char		*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_stash(fd, &stash[fd]))
		return (NULL);
	if(!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
		return (NULL);
	stash[fd] = trim_stash(stash[fd]);
	return (line);
}

static int	ft_stash(int fd, char **stash)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		bytes;
	char		*tmp;

	bytes = 1;
	while (!gnl_strchr(*stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (0);
		buf[bytes] = '\0';
		if (!*stash)
		{
			*stash = ft_strdup("");
			if (!*stash)
				return (0);
		}
		tmp = gnl_strjoin(*stash, buf);
		if (!tmp)
			return (0);
		*stash = tmp;
	}
	return (1);
}

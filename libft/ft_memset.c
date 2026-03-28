/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:57:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 08:57:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char *ptr;
	size_t i;

	ptr = (unsigned char *) s;
	i = 0;
	while(i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (s);

}
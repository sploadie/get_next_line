/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:54:38 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 12:48:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	char_c;
	unsigned char	*cap;

	if (n < 1)
		return (0);
	cap = (unsigned char*)s;
	char_c = (unsigned char)c;
	while (n-- > 0 && *cap != char_c)
		cap++;
	if (*cap == char_c)
		return (cap);
	return (0);
}

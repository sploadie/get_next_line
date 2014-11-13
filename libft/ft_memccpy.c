/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 22:16:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 12:31:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*saf_dst;
	unsigned char	*saf_src;

	saf_dst = (unsigned char*)dst;
	saf_src = (unsigned char*)src;
	i = 0;
	while (i < n && (unsigned char)saf_src[i] != (unsigned char)c)
	{
		saf_dst[i] = saf_src[i];
		i++;
	}
	if (saf_src[i] == (unsigned char)c)
	{
		saf_dst[i] = saf_src[i];
		return (saf_dst + i + 1);
	}
	return (0);
}

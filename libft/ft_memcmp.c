/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 18:03:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 12:35:55 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*saf_s1;
	unsigned char	*saf_s2;

	if (n < 1)
		return (0);
	n--;
	saf_s1 = (unsigned char*)s1;
	saf_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n && saf_s1[i] == saf_s2[i])
		i++;
	return ((unsigned char)saf_s1[i] - (unsigned char)saf_s2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:37:27 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 16:53:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void	*neospace;

	if (size == 0)
		return (NULL);
	neospace = (void *)malloc(size);
	if (!neospace)
		return (NULL);
	ft_bzero(neospace, size);
	return (neospace);
}

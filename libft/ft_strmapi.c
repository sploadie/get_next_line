/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:32:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:26:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*neoscript;

	neoscript = ft_strnew(ft_strlen((char*)s));
	if (!neoscript)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		neoscript[i] = f(i, s[i]);
		i++;
	}
	return (neoscript);
}

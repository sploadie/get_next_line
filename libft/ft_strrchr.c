/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:56:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:25:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	int		i;
	char	*last;

	if (c == '\0')
		return (str + ft_strlen(str));
	last = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last = str + i;
		i++;
	}
	return (last);
}

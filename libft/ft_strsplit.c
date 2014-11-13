/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 16:52:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**wary_init(char const *s, char c)
{
	unsigned int	i;
	unsigned int	ccount;
	char			**wary;

	i = 0;
	ccount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			ccount++;
		i++;
	}
	wary = (char **)malloc((ccount + 1) * sizeof(char*));
	if (!wary)
		return (NULL);
	wary[ccount] = NULL;
	return (wary + ccount);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	end;
	char			**wary;

	wary = wary_init((char*)s, c);
	if (!wary)
		return (NULL);
	end = ft_strlen((char*)s);
	i = end - 1;
	while (i > 0)
	{
		if (s[i] == c)
		{
			if (end != i + 1)
				*(--wary) = ft_strsub((char*)s, i + 1, end - i - 1);
			end = i;
		}
		i--;
	}
	if (s[i] != c)
		*(--wary) = ft_strsub((char*)s, i, end);
	return (wary);
}

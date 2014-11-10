/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:06:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/10 17:04:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_spill	*get_spill(int const fd)
{
	static t_list	*first_spill = NULL;
	t_list			*curr_spill;

	curr_spill = first_spill;
	while (curr_spill)
		if (curr_spill->fd == fd)
			return (curr_spill);
	curr_spill = (t_list*)malloc(sizeof(t_list*));
	if (!curr_spill)
		return (NULL);
	curr_spill->fd = fd;
	if (!(curr_spill->text = ft_strnew(0)))
		return (NULL);
	curr_spill->next = NULL;
	return (curr_spill);
	//SEARCH EXISTING SPILLS FOR FD
	//CREATE NEW SPILL IF FD NOT FOUND
	//RETURN SPILL
}

int		scoop_spill(t_spill *spill, char **line, char *cutoff)
{
	char	*to_free;

	if (!cutoff)
	{
		*line = spill->text;
		if (!(curr_spill->text = ft_strnew(0)))
			return (0);
		return (1);
	}
	*line = ft_strsub(spill->text, 0, cutoff - *(spill->text));
	if (!*line)
		return (0);
	to_free = spill->text;
	cutoff++;
	spill->text = ft_strsub(spill->text, cutoff, ft_strlen(cutoff));
	if (!spill->text)
		return (0);
	free(to_free);
	return (1);
	//GIVE LINE RELEVANT SECTION OF SPILL
	//RESIZE SPILL
}

int		read_spill(t_spill *spill, char **line)
{
	char	*line_end;

	if ((line_end = ft_strchr(spill->text)))
	{
		if (!scoop_spill(spill, line, line_end))
			return (-1);
		return (1);
	}
	return (0);
	// PASS TO SCOOP_SPILL
	// 1 - TO \N WAS FOUND
	// 0 - \N WAS NOT REACHED
	//-1 - MALLOC ERROR
}

int		read_to_spill(int const fd, t_spill *spill, char **line)
{
	int				ret;
	int				spill_ret;
	char			buf[BUF_SIZE + 1];
	char			*to_free;

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		// CODE HERE
		to_free = spill->text;
		spill->text = ft_join(spill->text, buf);
		free(to_free);
		spill_ret = read_spill(spill, line);
		if (spill_ret == -1)
			return (-1);
		else if (spill_ret == 1)
			return (1);
		// spill_ret == 0 THEN CONTINUE
	}
	if (ret != 0)
		return (-1);
	// Buf already has \0?
	to_free = spill->text;
	spill->text = ft_join(spill->text, buf);
	free(to_free);
	if (!scoop_spill(spill, line, NULL))
		return (-1);
	return (0);
	// PASS TO SPILL
	// SCOOP_SPILL TO \0
	// 1 - TO \N WAS FOUND
	// 0 - END OF FILE
	//-1 - MALLOC ERROR
}

int		get_next_line(int const fd, char **line)
{
	t_spill	*spill;
	int		read_ret;

	spill = get_spill(fd);
	if (!spill)
		return (-1);
	return (read_to_spill(fd, spill, line));
	// PASS TO GET_SPILL
	// PASS TO READ_TO_SPILL
}

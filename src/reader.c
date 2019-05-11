/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:59:15 by ikozlov           #+#    #+#             */
/*   Updated: 2019/05/10 17:25:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <unistd.h>

int		valid_piece(const char *str)
{
	int		i;
	int		edge;

	i = -1;
	edge = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i > 4 && str[i - 5] == '#')
				edge++;
			if (i < 14 && str[i + 5] == '#')
				edge++;
			if (i % 5 > 0 && str[i - 1] == '#')
				edge++;
			if (i % 5 < 3 && str[i + 1] == '#')
				edge++;
		}
	}
	return (edge == 6 || edge == 8);
}

int		valid_block(const char *str, int size)
{
	int		i;
	int		hex;

	i = -1;
	hex = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] == '#')
				hex++;
			else if (str[i] != '.')
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
	}
	if (size == 21 && str[PIECE_SIZE] != '\n')
		return (0);
	if (hex != 4 || !valid_piece(str))
		return (0);
	return (1);
}

int		read_pieces(int fd, t_piece *pieces)
{
	int			pos;
	size_t		ret;
	int			last_read;
	char		buf[PIECE_SIZE + 1];

	pos = 0;
	while ((ret = read(fd, buf, PIECE_SIZE + 1)))
	{
		if (ret < PIECE_SIZE || !valid_block(buf, ret))
			return (-1);
		pieces[pos] = create_piece('A' + pos, buf);
		pos++;
		last_read = ret;
	}
	return (last_read == 20 ? pos : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:50:35 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/08 16:52:27 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "memory.h"

void			set_hexes(t_piece *p, char *value)
{
	int			i;
	int			x;
	int			y;
	int			pos;

	i = -1;
	pos = 0;
	x = ft_strchri(p->value, '#') % 5;
	y = ft_strchri(p->value, '#') / 5;
	while (++i < PIECE_SIZE)
		if (value[i] == '#')
		{
			p->hex[pos].x = (i % 5) - x;
			p->hex[pos].y = (i / 5) - y;
			pos++;
		}
}
t_piece		create_piece(char id, char *value)
{
	t_piece		ret;

	ret.id = id;
	ft_memcpy(ret.value, value, PIECE_SIZE);
	// set_w_and_h(&ret);
	set_hexes(&ret, value);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:50:35 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/10 16:18:14 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "memory.h"
#include "ftstring.h"

void			set_w_and_h(t_piece *p, char *value)
{
	int				i;
	int				minx;
	int				miny;
	int				maxx;
	int				maxy;

	i = -1;
	minx = 5;
	miny = 5;
	maxx = 0;
	maxy = 0;
	while (++i < PIECE_SIZE)
		if (value[i] == '#')
		{
			minx = i % 5 < minx ? i % 5 : minx;
			miny = i / 5 < miny ? i / 5 : miny;
			maxx = i % 5 > maxx ? i % 5 : maxx;
			maxy = i / 5 > maxy ? i / 5 : maxy;
		}
	p->w = maxx - minx + 1;
	p->h = maxy - miny + 1;
}

void			normalize_hexes(t_piece *p)
{
	int		i;
	int		minx;
	int		miny;

	i = -1;
	minx = p->hex[0].x;
	miny = p->hex[0].y;
	while (++i < 4)
	{
		minx = p->hex[i].x < minx ? p->hex[i].x : minx;
		miny = p->hex[i].y < miny ? p->hex[i].y : miny;
	}
	i = -1;
	while (++i < 4)
	{
		if (minx < 0)
			p->hex[i].x -= minx;
		if (miny < 0)
			p->hex[i].y -= miny;
	}
}

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

t_piece			create_piece(char id, char *value)
{
	t_piece		ret;

	ret.id = id;
	ft_memcpy(ret.value, value, PIECE_SIZE);
	set_w_and_h(&ret, value);
	set_hexes(&ret, value);
	normalize_hexes(&ret);
	return (ret);
}

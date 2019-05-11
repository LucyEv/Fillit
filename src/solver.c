/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:08:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/10 16:26:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "ft_printf.h"

int			can_place_piece(t_map *m, t_piece p, int x, int y)
{
	int		i;
	t_point	hex;

	i = -1;
	while (++i < 4)
	{
		hex = p.hex[i];
		if (m->map[y + hex.y][x + hex.x] != 0)
			return (0);
	}
	return (1);
}

void		clear_piece(t_map *m, t_piece p, int x, int y)
{
	int		i;
	t_point	hex;

	i = -1;
	while (++i < 4)
	{
		hex = p.hex[i];
		m->map[y + hex.y][x + hex.x] = 0;
	}
}

void		place_piece(t_map *m, t_piece p, int x, int y)
{
	int		i;
	t_point	hex;

	i = -1;
	while (++i < 4)
	{
		hex = p.hex[i];
		m->map[y + hex.y][x + hex.x] = p.id;
	}
}

int			solve_map(t_map *m, t_piece *pieces, int pos, int count)
{
	int		x;
	int		y;
	t_piece	p;

	if (pos == count)
		return (1);
	y = -1;
	p = pieces[pos];
	while (++y < (m->size - p.h + 1))
	{
		x = -1;
		while (++x < (m->size - p.w + 1))
		{
			if (can_place_piece(m, p, x, y))
			{
				place_piece(m, p, x, y);
				if (PRETTY_FILLIT)
					print_map(*m);
				if (solve_map(m, pieces, pos + 1, count))
					return (1);
				clear_piece(m, p, x, y);
			}
		}
	}
	return (0);
}

t_map		solve(t_piece *pieces, int count)
{
	t_map		map;

	map.size = 1;
	clear_map(&map);
	while (map.size * map.size < count * 4)
		map.size++;
	while (!solve_map(&map, pieces, 0, count))
	{
		map.size++;
		clear_map(&map);
	}
	return (map);
}

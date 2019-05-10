/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:08:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/09 19:31:16 by ivankozlov       ###   ########.fr       */
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
		if (m->map[x + hex.x][y + hex.y] != 0)
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
		m->map[x + hex.x][y + hex.y] = 0;
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
		m->map[x + hex.x][y + hex.y] = p.id;
	}
}

int		g_step = 0;

int			solve_map(t_map *m, t_piece *pieces, int pos, int count)
{
	int		x;
	int		y;
	t_piece	p;

	if (g_step >= 10000)
		return (0);
	g_step++;
	if (pos == count)
		return (1);
	y = -1;
	p = pieces[pos];
	while (++y < m->size - p.h + 1)
	{
		x = -1;
		while (++x < m->size - p.w + 1)
		{
			g_step++;
			if (can_place_piece(m, p, x, y) && g_step < 10000)
			{
				place_piece(m, p, x, y);
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
		g_step = 0;
		map.size++;
		clear_map(&map);
	}
	return (map);
}

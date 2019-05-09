/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:08:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/08 21:24:44 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve_map(t_map *m, t_piece *pieces, int pos, int size)
{
	int		x;
	int		y;
	t_piece	p;

	if (pos == size)
		return (1);
	y = -1;
	p = pieces[pos];
	while (++y < m->size - p.h + 1)
	{
		x = -1;
		while (++x < m->size - p.w + 1)
		{
			if (place_piece(m, p, x, y))
			{
				if (solve_map(m, pieces, pos + 1, size))
					return (1);
				else
					clear_piece(m, p, x, y);
			}
		}
	}
	return (0);
}

t_map		solve(t_piece *pieces, int size)
{
	t_map		map;

	clear_map(&map);
	while (!solve_map(&map, pieces, 0, size))
	{
		map.size++;
		clear_map(&map);
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:54:14 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/09 19:23:49 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "ft_printf.h"

void		print_map_debug(t_map map)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < MAX_MAP_SIZE)
	{
		j = -1;
		while (++j < MAX_MAP_SIZE)
		{
			ft_printf("%.2u", map.map[i][j]);
		}
		ft_printf("\n");
	}
}

void		print_pieces(t_piece *pieces, int size)
{
	int			i;
	t_piece		p;

	i = -1;
	while (++i < size)
	{
		p = pieces[i];
		ft_printf("id: %c w: %d h: %d\n", p.id, p.w, p.h);
		ft_printf("h0 %d %d\n", p.hex[0].x, p.hex[0].y);
		ft_printf("h1 %d %d\n", p.hex[1].x, p.hex[1].y);
		ft_printf("h2 %d %d\n", p.hex[2].x, p.hex[2].y);
		ft_printf("h3 %d %d\n", p.hex[3].x, p.hex[3].y);
		ft_printf("%s\n", pieces[i].value);
	}
}

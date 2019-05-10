/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:23:02 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/09 19:29:13 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "memory.h"
#include "colors.h"
#include "ftstring.h"
#include "ft_printf.h"

void		print_char_colors(char ch)
{
	char						*color;
	static	char		*colors[] = {
		RED, GRN, YEL, BLU, MAG, CYN
	};

	color = WHT;
	if (ch != 0)
		color = colors[(ch - 'A') % 6];
	else
		ch = '.';
	ft_printf("%s%c%s", color, ch, RESET);
}

void		print_map(t_map map)
{
	size_t		i;
	size_t		j;

	// CLEAR_SCREEN();
	i = -1;
	while (++i < map.size)
	{
		j = -1;
		while (++j < map.size)
			print_char_colors(map.map[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
	// usleep(100000);
}

void		clear_map(t_map *m)
{
	ft_bzero(m->map, sizeof(char) * MAX_MAP_SIZE * MAX_MAP_SIZE);
}

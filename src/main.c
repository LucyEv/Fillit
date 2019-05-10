/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:01:08 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/09 19:28:03 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "ft_printf.h"

#include <fcntl.h>

int		main(int ac, char *av[])
{
	int			fd;
	int			count;
	t_piece		tetris[MAX_PIECES];

	if (ac != 2)
		error_handler(ERR_INVALID_ARG, USAGE);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_handler(ERR_FILE_NOT_FOUND, av[1]);
	count = read_pieces(fd, tetris);
	if (count < 0)
		error_handler(ERR_INVALID_FILE, av[1]);
	print_pieces(tetris, count);
	print_map(solve(tetris, count));
	return (0);
}

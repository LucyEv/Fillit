/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:28 by ikozlov           #+#    #+#             */
/*   Updated: 2019/05/10 15:44:40 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stddef.h>

# include "ft_math.h"

# define MAX_PIECES 26
# define PIECE_SIZE 20
# define MAX_MAP_SIZE 10
# define PRETTY_FILLIT 0
# define USAGE "usage: ./fillit [input_file]"

struct						s_map
{
	int						size;
	char					map[MAX_MAP_SIZE][MAX_MAP_SIZE];
};
typedef struct s_map		t_map;

struct						s_piece
{
	char		id;
	char		value[PIECE_SIZE];
	t_point		hex[4];
	int			w;
	int			h;
};
typedef struct s_piece		t_piece;

enum						e_err
{
	ERR_INVALID_ARG,
	ERR_FILE_NOT_FOUND,
	ERR_INVALID_FILE,
};

void						error_handler(int errcode, char *msg);
int							read_pieces(int fd, t_piece *pieces);
t_piece						create_piece(char id, char *value);
t_map						solve(t_piece *pieces, int size);

void						clear_map(t_map *m);
void						print_map(t_map map);

void						print_pieces(t_piece *pieces, int size);
void						print_map_debug(t_map map);

#endif

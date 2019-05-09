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

t_piece		create_piece(char id, char *value)
{
	t_piece		ret;

	ret.id = id;
	ft_memcpy(ret.value, value, PIECE_SIZE);
	return (ret);
}

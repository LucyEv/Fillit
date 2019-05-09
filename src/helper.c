/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:54:14 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/08 17:03:06 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "ft_printf.h"

void		print_pieces(t_piece *pieces, int size)
{
	int			i;

	i = -1;
	while (++i < size)
	{
		ft_printf("id: %c\n", pieces[i].id);
		ft_printf("%s\n", pieces[i].value);
	}
}

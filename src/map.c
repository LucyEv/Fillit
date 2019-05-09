/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:23:02 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/08 18:16:13 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "memory.h"

void		clear_map(t_map *m)
{
	ft_bzero(m->map, sizeof(char) * MAX_MAP_SIZE * MAX_MAP_SIZE);
}

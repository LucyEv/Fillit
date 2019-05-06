/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:01:08 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/06 15:03:55 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char *av[])
{
	if (ac == 2)
		ft_printf("Hello, my first arg is: %s\n", av[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:34:50 by ikozlov           #+#    #+#             */
/*   Updated: 2019/05/06 17:55:31 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "ft_printf.h"

#include <stdlib.h>

void		error_handler(int errcode, char *msg)
{
	if (errcode == ERR_FILE_NOT_FOUND)
		ft_printf("File not found: %s\n", msg);
	else if (errcode == ERR_INVALID_FILE)
		ft_printf("File is invalid: %s\n", msg);
	else
		ft_printf("%s\n", msg);
	exit(-1);
}

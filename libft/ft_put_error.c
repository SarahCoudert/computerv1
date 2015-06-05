/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 14:40:57 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/05 14:40:58 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_put_error(char *msg, int fd, int exit_flag)
{
	ft_putendl_fd(msg, fd);
	ft_putendl("We are exiting the programm");
	exit(exit_flag);
}

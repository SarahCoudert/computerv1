/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:43:41 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/03 17:16:35 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

void		test_square();
/*
** Input examples :
** "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
** seconde degres
** "5 * X^0 + 4 * X^1 = 4 * X^0"
** premier degres
** "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
** troisieme degres (pas a gerer)
*/

int		main(int ac, char **av)
{
	t_list	*list;

	list = NULL;
	(void)av;
	if (ac == 2)
	{
		list = parse(av[1]);
	//	sort_list(list);
	}
	else
		ft_put_error("Wrong number of arguments", 1, -1);
	return (0);
}

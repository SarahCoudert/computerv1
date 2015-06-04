/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:43:41 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/04 22:14:16 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

/*
** Input examples :
** "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
** seconde degres
** "5 * X^0 + 4 * X^1 = 4 * X^0"
** premier degres
** "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
** troisieme degres (pas a gerer)
*/

#include <stdio.h>

void		read_list(t_list *list, char *s)
{
	int i;
	int l;

	l = ft_lstcountelements(list);
	i = 0;
	printf ("%s\n\n", s);
	for (i = 0; i < l; i++)
	{
		printf("i = %d\n", i);
		printf ("sign = %d\n", (int)STRU->sign);
		printf ("multi = %f\n", STRU->multi);
		printf ("exp = %d\n\n", (int)STRU->exp);
		list = list->next;
	}
	printf ("\n\n");
}

void	solv(t_list *list);

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*ptr;
	list = NULL;
	(void)av;
	if (ac == 2)
	{
		list = parse(av[1]);
		read_list(list, "parse");
		sort_list(list);
		read_list(list, "sort");
		ptr = add_list(list);
		read_list(ptr, "add");
		form_reduit(ptr);
		solv(ptr);
		ft_lstdel(&list, del);
		ft_lstdel(&ptr, del);
	}
	else
		ft_put_error("\033[31mWrong number of arguments", 1, -1);
	return (0);
}

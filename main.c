/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:43:41 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/05 20:03:47 by mgrimald         ###   ########.fr       */
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

int		ft_skip(char *s, int *i, int b)
{
	int	n;

	n = 1;
	while (ft_isspace(s[*i]) || s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '+' || s[*i] == '-')
		{
			if (b == 1)
			{
				if (s[*i] == '-')
					n *= -1;
			}
			else
				return (n);
		}
		*i = *i + 1;
	}
	return (n);
}

void	read_list(t_list *list, char *s)
{
	printf ("\n%s\n", s);
	while (list)
	{
		printf ("sign = %d\n", STRU->sign);
		printf ("multi = %f\n", STRU->multi);
		printf ("exp = %d\n\n", STRU->exp);
		printf ("exp = %d\n\n", (int)STRU->exp);
		list = list->next;
	}
	printf ("\n\n");
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*ptr;

	list = NULL;
	if (ac != 2)
		ft_put_error("\033[31mWrong number of arguments", 1, -1);
	list = parse(av[1]);
	sort_list(list);
	form_reduit(list, 0);
	ptr = add_list(list);
	form_reduit(ptr, 1);
	if (((t_stru*)(ptr->content))->exp < 0)
		printf("\033[31mExposant smaller than 0,\nunable to solve\033[0m");
	else
	{
		solv(ptr);
		printf("\033[0m\nis the simplified form of\033[36m\n====>\t%s\033[0m",
			av[1]);
		if (!ft_strchr(av[1], '='))
			printf(" = 0");
	}
	printf("\n");
	ft_lstdel(&list, del);
	ft_lstdel(&ptr, del);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 14:32:06 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/04 21:41:21 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"
#include <stdio.h>

void		resolve_other(double b, double c)
{
	if (b != 0)
		printf("Lineare equation :\n\tX = %f / %f\n==> (X - (%f)) = 0", -c, b, c);
	else if (c != 0)
		printf("Pretty funny but even with irreal number, it is unpossible to solve this equation\n");
	else
		printf("0 = 0\nX is not in the equation so it could be anything\n(tous les nombres reels sont solutions)\n");
}

void		resolve_square(double a, double b, double c)
{
	int			delta;
	int			i;

	delta = b * b - 4 * a * c;
	i = 0;
	ft_putstr("\n\033[32m△ = ");
	ft_putnbr(delta);
	if (delta < 0 && (i = 1))
		delta *= -1;
	if (delta == 0)
	{
		ft_putstr("\n\n\033[32m==> △  egal to 0\n↪ Only one solution: \n\t\tX = ");
		ft_putnbr((-b) / (2 * a));
		ft_putstr("\n⇨ (X - ");
		ft_putnbr((-b) / (2 * a));
		ft_putstr(")² = 0");
	}
	else
	{
		ft_putstr("\n\n\033[32m==> △  different from 0 \n↪ Two solutions: \n");
		printf("    %f ± √(%d)\n_________________________\n     (2 * %f)\n\n"
			, -b, delta, a);
		ft_putstr("\tX_1 = ");
		if (i == 1)
		{
			ft_putnbr((-b) / (2 * a));
			ft_putstr(" + i * ");
			ft_putnbr((int)square_root(delta) / (2 * a));
		}
		else
			ft_putnbr((-b) + (int)square_root(delta) / (2 * a));
		ft_putstr("\n\tX_2 = ");
		if (i == 1)
		{
			ft_putnbr((-b) / (2 * a));
			ft_putstr(" - i * ");
			ft_putnbr((int)square_root(delta) / (2 * a));
		}
		else
			ft_putnbr((-b) - (int)square_root(delta) / (2 * a));
	}
	ft_putendl("");
}

void		solv(t_list *list)
{
	double		a;
	double		b;
	double		c;

	if (STRU->exp > 2)
		ft_put_error("\033[31mExposant bigger than 2\nUnable to resolve", 2, -1);
	if ((a = 0) || STRU->exp == 2)
	{
		a = STRU->multi * STRU->sign;
		list = list->next;
	}
	if ((b = 0) || (list != NULL && STRU->exp == 1))
	{
		b = STRU->multi * STRU->sign;
		list = list->next;
	}
	if ((c = 0) || (list != NULL && STRU->exp == 0))
	{
		c = STRU->multi * STRU->sign;
		list = list->next;
	}
	if (list != NULL && STRU->exp < 0)
		ft_put_error("\033[31mExposant smaller than 0\nUnable to solve", 2, -1);
	if (a != 0)
		resolve_square(a, b, c);
	else
		resolve_other(b, c);
}

void		form_reduit(t_list *list)
{
	t_list *ptr;

	ptr = list;
	ft_putstr("Forme reduite :");
	while (list)
	{
		printf(" %f * X^%d ", STRU->multi, STRU->exp);
		if (list->next && STRU_NEXT->multi * STRU_NEXT->sign >= 0)
			printf("+");
		else if (list->next && STRU_NEXT->multi * STRU_NEXT->sign < 0)
			printf("-");
		list = list->next;
	}
	printf(" = 0\n");
	list = ptr;
}

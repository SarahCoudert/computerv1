/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 14:32:06 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/04 15:58:30 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

void		resolve(double a, double b, double c)
{
	int			delta;
	int			i;

	delta = b * b - 4 * a * c;
	i = 0;
	ft_putnbr(delta);
	ft_putendl("");
	ft_putnbr(a);
	ft_putendl("");
	ft_putnbr(b);
	ft_putendl("");
	ft_putnbr(c);
	ft_putendl("");
	if (delta < 0 && (i = 1))
		delta *= -1;
	if (delta == 0)
	{
		ft_putstr("\ndelta == 0\n\tonly one solution: \n\t\tX = ");
		ft_putnbr((-b) / (2 * a));
		ft_putstr("\n==> (X - ");
		ft_putnbr((-b) / (2 * a));
		ft_putstr(")^2 = 0");
	}
	else
	{
		ft_putstr("\ndelta != 0 \n\ttwo solutions: \n\t\tX_1 = ");
		if (i == 1)
		{
			ft_putnbr((-b) / (2 * a));
			ft_putstr(" + i * ");
			ft_putnbr((int)square_root(delta) / (2 * a));
		}
		else
			ft_putnbr((-b) + (int)square_root(delta) / (2 * a));
		ft_putstr("\n\t\tX_2 = ");
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
		ft_put_error("exposant bigger than 2\nunable to resolve", 2, -1);
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
		ft_putendl("a");
		c = STRU->multi * STRU->sign;
		list = list->next;
	}
	if (list != NULL && STRU->exp < 0)
		ft_put_error("exposant smaller than 2\nunable to resolve", 2, -1);
	resolve(a, b, c);
}

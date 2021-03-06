/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 14:32:06 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/05 20:39:37 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

void		resolve_other(double b, double c)
{
	if (b != 0)
	{
		printf("First degree equation resolution :\n\tX = (-c / b)\n\t");
		printf ("X = (%g / %g)\n\t\033[32m", -c, b);
		printf("Solution : X = %g\n\033[00m", ((-c) / b));
		printf("\t(X - (c/b)) = 0\n\t\033[35m(X - (%g))\033[0m = 0", -c / b);
	}
	else if (c != 0)
	{
		printf("YOU prove me that a == 0 with a != 0\n");
		printf("it is unpossible to solve this equation -_-'' \n");
		printf("\033[1;35m\t%g\033[0m = 0", c);
	}
	else
	{
		printf("0 = 0\nX is not in the equation so it could be anything\n");
		printf("(All real numbers are solution)\n");
		printf("\033[1;35m\t%g\033[0m = 0", c);
	}
}

void		resolve_square(double a, double b, double c)
{
	double	delta;
	int		i;

	delta = b * b - 4 * a * c;
	printf("\nfull resolution formula : X = (-b +/- \\/(b^2 - 4ac)) / 2a\n");
	printf("\n\033[32mDelta = %g\na = %g\nb = %g\nc = %g\n", delta, a, b, c);
	i = 0;
	if (delta < 0 && (i = 1))
		delta *= -1;
	if (delta == 0)
	{
		printf("\n\n\033[32mDelta egal to 0\n-> Only one solution: \n\tX = ");
		printf("%g\n\n\t(X - (%g))^2 = 0", (-b) / (2 * a), (-b) / (2 * a));
	}
	else
		print_res(a, b, delta, i);
	if (i == 0)
		printf("\n\t\033[1;35m(X - (%g)) * (X - (%g))",
				((-b) + square_root(delta)) / (2 * a), ((-b)
				- square_root(delta)) / (2 * a));
	else
		printf("\n\t\033[1;35m(X - (%g + i * (%g))) * (X - (%g + i * (%g)))",
				(-b) / (2 * a), square_root(delta) / (2 * a),
				(-b) / (2 * a), square_root(delta) / (2 * a));
	printf("\033[0m = 0");
}

void		print_res(double a, double b, double delta, int i)
{
	printf("\n\n\033[32mDelta  different from 0 \n-> Two solutions: \n");
	printf("\t%g ± √(%g)\n _________________________\n\t(2 * %g)\n\n"
		, -b, delta, a);
	printf("\tX_1 = ");
	if (i == 1)
		printf("%g + i * %g", (-b) / (2 * a), square_root(delta) / (2 * a));
	else
		printf("%g", ((-b) + square_root(delta)) / (2 * a));
	printf("\n\tX_2 = ");
	if (i == 1)
		printf("%g - i * %g", (-b) / (2 * a), square_root(delta) / (2 * a));
	else
		printf("%g", ((-b) - square_root(delta)) / (2 * a));
}

void		solv(t_list *list)
{
	double	a;
	double	b;
	double	c;

	if ((c = 0) || (list != NULL && STRU->exp == 0))
	{
		c = STRU->multi * STRU->sign;
		list = list->next;
	}
	if ((b = 0) || (list != NULL && STRU->exp == 1))
	{
		b = STRU->multi * STRU->sign;
		list = list->next;
	}
	if ((a = 0) || (list != NULL && STRU->exp == 2))
		a = STRU->multi * STRU->sign;
	if ((list && STRU->exp > 2) || (list && list->next && STRU_NEXT->exp > 2))
		printf("\033[31mExposant bigger than 2\nInsolvable\033[0m\n");
	else if (a != 0 && (list == NULL || (STRU->exp <= 2)))
		resolve_square(a, b, c);
	else
		resolve_other(b, c);
}

void		form_reduit(t_list *list, int etape)
{
	t_list	*ptr;

	ptr = list;
	if (etape == 1)
		printf("Reduced form : \033[36m");
	else
		printf("\033[46mTransitional step :\033[0m \033[36m");
	while (list)
	{
		if (ptr == list || STRU->multi * STRU->sign >= 0)
			printf(" %g * X^%d ", STRU->multi * STRU->sign, STRU->exp);
		else
			printf(" %g * X^%d ", -1 * STRU->multi * STRU->sign, STRU->exp);
		if (list->next && STRU_NEXT->multi * STRU_NEXT->sign >= 0)
			printf("+");
		else if (list->next && STRU_NEXT->multi * STRU_NEXT->sign < 0)
			printf("-");
		list = list->next;
	}
	printf("\033[0m= 0\n");
	list = ptr;
	if (etape == 1)
		printf("\033[104mPolynomial degree :\033[0m %d\n", STRU->exp);
	else
		printf("\n");
}

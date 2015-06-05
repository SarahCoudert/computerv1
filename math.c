/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:31:00 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/05 11:31:03 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

double		square_root(double n)
{
	double	x;
	double	y;
	double	e;

	y = 1;
	x = n;
	e = 0.000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

t_list		*sort_list(t_list *list)
{
	t_list	*ptr;
	t_stru	temp;

	ptr = list;
	while (list->next)
	{
		if (STRU->exp < STRU_NEXT->exp)
		{
			temp.exp = (STRU)->exp;
			(STRU)->exp = STRU_NEXT->exp;
			STRU_NEXT->exp = temp.exp;
			temp.multi = STRU->multi;
			(STRU)->multi = STRU_NEXT->multi;
			STRU_NEXT->multi = temp.multi;
			temp.sign = STRU->sign;
			STRU->sign = STRU_NEXT->sign;
			STRU_NEXT->sign = temp.sign;
			list = ptr;
			continue ;
		}
		else
			list = list->next;
	}
	return (ptr);
}

t_list		*add_list(t_list *list)
{
	t_list		*ret;
	t_stru		*stru;
	int			exp;

	ret = NULL;
	stru = (t_stru*)ft_strnew(sizeof(t_stru));
	while (list)
	{
		stru->multi = STRU->multi * STRU->sign;
		stru->exp = STRU->exp;
		stru->sign = 1;
		while (list->next && STRU->exp == STRU_NEXT->exp)
		{
			stru->multi += STRU_NEXT->multi * STRU_NEXT->sign;
			list = list->next;
		}
		if (stru->multi != 0.0)
			ft_lstaddend(stru, sizeof(t_stru), &ret);
		ft_bzero(stru, sizeof(t_stru));
		list = list->next;
	}
	if (ret == NULL)
		ft_lstaddend(stru, sizeof(t_stru), &ret);
	return (ret);
}

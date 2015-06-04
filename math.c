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
	int		temp;

	temp = 0;
	ptr = list;
	while (list->next)
	{
		if ((int)(STRU->exp < (int)STRU_NEXT->exp))
		{
 			temp = (int)(STRU)->exp;
			(STRU)->exp = (int)STRU_NEXT->exp;
			STRU_NEXT->exp = temp;
			temp = (int)STRU->multi;
			(STRU)->multi = (int)STRU_NEXT->multi;
			STRU_NEXT->multi = temp;
			temp = (int)STRU->sign;
			STRU->sign = (int)STRU_NEXT->sign;
			STRU_NEXT->sign = temp;
			list = ptr;
			continue ;
		}
		else
			list = list->next;
	}
	return (ptr);
}

#include <stdio.h>

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
		while (list && list->next && STRU->exp == STRU_NEXT->exp)
		{
			stru->multi += STRU_NEXT->exp * STRU_NEXT->sign;
			list = list->next;
		}
		ft_lstaddend(stru, sizeof(t_stru), &ret);
		ft_bzero(stru, sizeof(t_stru));
		list = list->next;
	}
	if (ret == NULL)
		ft_lstaddend(stru, sizeof(t_stru), &ret);
	return (ret);
}

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

t_list		*add_list(t_list *list)
{
	t_list		*ptr;
	t_list		*ret;
	t_stru		*stru;
	int			exp;

	exp = 0;
	stru = NULL;
	ret = NULL;
	ptr = list;
	while (list)
	{
		ft_strnew(sizeof(t_stru));
		while (list && STRU->exp == STRU_NEXT->exp)
		{
			stru->sign = 1;
			stru->exp = STRU->exp;
			stru->multi = (STRU_NEXT-> multi * STRU_NEXT->sign) +
			((STRU->multi) * (STRU->sign));
			list = list->next;
		}
			ft_lstaddend(stru, sizeof(stru), &ret);
			if (list)
				list = list->next;
	}
	ft_lstdel(&ptr, del);
	return (ret);
}

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
			continue ;
		}
		else
			list = list->next;
	}
	return (ptr);
}
/*
t_list		*add_list(t_list *list)
{
	t_list		*ptr;
	t_list		*ret;
	t_stru		*stru;

	stru = NULL;
	ret = NULL;
	ptr = list;
	while (ptr->next)
	{
		if (((t_stru*)(ptr->content)->exp) == (((t_stru*)(ptr->next->content)->exp)))
		{
			stru = (t_stru*)ft_strnew(sizeof(t_stru));
			ft_bzero(stru);
			stru->exp = ((t_stru*)(ptr->content)->exp) + (((t_stru*)(ptr->next->content)->exp));
			stru->multi = ((t_stru*)(ptr->content)->multi) * (((t_stru*)(ptr->next->content)->multi));
			stru->sign = ((t_stru*)(ptr->content)->sign) * (((t_stru*)(ptr->next->content)->sign));
			ft_lstaddend(stru, sizeof(t_stru), &ret);
		}
		else
		{
			
		}
		ptr = ptr->next;

	}
}*/
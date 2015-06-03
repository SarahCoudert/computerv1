#include "computer.h"

double		square_root(double n)
{
	double	x;
	double	y;
	double	e;

	y = 1;
	x = n;
	e = 0,000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

t_str		sort_stru(s_stru *stru)
{
	t_stru	*ptr;
	int		temp;

	temp = 0;
	ptr = stru;
	while (stru->next)
	{
		if (stru->exp < stru->next->exp)
		{
			temp = stru->exp;
			stru->exp = stru->next->exp;
			stru->next->exp = temp;
			temp = stru->multi;
			stru->multi = stru->next->multi;
			stru->next->multi = temp;
			temp = stru->sign;
			stru->sign = stru->next->sign;
			stru->next->sign = temp;
			continue ;
		}
		else
			stru = stru->next;
	}
	return (ptr);
}
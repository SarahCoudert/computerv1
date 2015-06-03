/*
 ** Input examples :
 ** "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
 ** seconde degres
 ** forme reduite : "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
 ** "4 * X^0 + 4 * X^1 = 4 * X^0"
 ** premier degres
 ** "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
 ** troisieme degres (pas a gerer)
 */

#include "computer.h"

t_list		*parse(char *s)
{
	int		i;
	t_list	*lst;
	t_stru*	stru;
	int		n;
	int		default_n;

	stru = (t_stru*)ft_strnew(sizeof(t_stru));
	i = 0;
	n = 1;
	lst = NULL;
	default_n = 1;
	while (s[i] != '\0')
	{
		n *= ft_skip(s, &i, 1);
		stru = fill_stru(&i, stru, n, s);
		ft_putnbr(stru->sign);
		ft_putendl("");
		ft_putnbr(stru->multi);
		ft_putendl("");
		ft_putnbr(stru->exp);
		ft_putendl("\n");
		ft_lstaddend((void*)stru, sizeof(t_stru), &lst);
		if (s[i] == '=' && ++i)
		{
			if (default_n == -1)
				ft_put_error("WARNING : Two '=' signs in string", 1, -1);
			default_n = -1;
		}
		n = default_n;
	}
	free(stru);
	return (lst);
}

int			ft_skip(char *s, int *i, int b)
{
	int		n;

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

t_stru		*fill_stru(int *i, t_stru *stru, int sign, char *s)
{
	int		bol;
	int		mult;


	ft_bzero(stru, sizeof(t_stru));
	stru->sign = sign;
	bol = 0;
	mult = 1;
	while (s[*i] != '\0' && ((s[*i] != '-' && s[*i] != '+') || mult == 1) && s[*i] != '=')
	{
		stru->sign *= ft_skip(s, i, mult);
		if ((ft_isdigit(s[*i])) != 0)
		{
			if (bol == 0)
				stru->multi = ft_atoi(s + *i);
			else if (mult == 1)
				stru->multi *= ft_atoi(s + *i);
			else
				ft_put_error("error : nbr_1    nbr_2 (NO MULT SIGN)", 2, -1);
			while (s[*i] && (ft_isdigit(s[*i]) != 0))
				*i = *i + 1;
			bol = 1;
			mult = 0;
		}
		else if (s[*i] == '*')
		{
			*i = *i + 1;
			mult = 1;
		}
		else if (s[*i] == 'X' || s[*i] == 'x')
		{
			*i = *i + 1;
			if (bol != 1 && stru->multi == 0)
				stru->multi = 1;
			stru->exp = 1;
			ft_skip(s, i, 0);
			if (s[*i] == '^')
			{
				*i = *i + 1;
				mult = ft_skip(s, i, 1);
				stru->exp = ft_atoi(s + *i) * mult;
				while (s[*i] && ft_isdigit(s[*i]))
					*i = *i + 1;
			}
			ft_skip(s, i, 0);
			mult = 0;
		}
	}
	if (mult == 1)
		ft_put_error("* =", 2, -1);
	return (stru);
}

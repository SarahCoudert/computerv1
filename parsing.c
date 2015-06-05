/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 17:22:57 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/05 13:12:22 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

static void		sub_parse(char *s, int *i, t_stru *stru, t_list *list)
{
	printf("%s\n", s + *i);
	stru->sign *= ft_skip(s, i, 1);
	stru = fill_stru(i, stru, s);
	printf("sign: %d\nmult: %f\nexp: %d\n", stru->sign, stru->multi, stru->exp);
	ft_lstaddend((void*)stru, sizeof(t_stru), &list);
	ft_bzero(stru, sizeof(t_stru));
}

t_list	*parse(char *s)
{
	int			i;
	t_list		*list;
	t_stru		*stru;
	int			default_n;

	stru = (t_stru*)ft_strnew(sizeof(t_stru));
	list = NULL;
	default_n = 1;
	ft_skip(s, &i, 0);
	s = s + i;
	i = 0;
	while ((stru->sign = default_n) && s[i] != '\0')
	{
		sub_parse(s, &i, stru, list);
		if (s[i] == '=' && ++i)
		{
			if (default_n == -1)
				ft_put_error("WARNING : Two '=' signs in string", 1, -1);
			default_n = -1;
		}
	}
	if (i == 0)
		ft_put_error("empty line", 2, -1);
	free(stru);
	return (list);
}

int		ft_skip(char *s, int *i, int b)
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

static int	fill_multi(int *i, char *s, int *bol, int *mult)
{
	double		v;

	if (*bol == 0)
		v = atof(s + *i);
	else if (*mult == 1)
		v *= atof(s + *i);
	else
		ft_put_error("parse error: missing '*' between around numbers", 2, -1);
	while (ft_isdigit(s[*i]) != 0)
		*i = *i + 1;
	if (s[*i] == '.')
	{
		*i = *i + 1;
		while (ft_isdigit(s[*i]) != 0)
			*i = *i + 1;
	}
	*bol = 1;
	*mult = 0;
	return (v);
}

static int	fill_exp(int *i, char *s, int bol, t_stru *stru)
{
	*i = *i + 1;
	if (bol != 1 && stru->multi == 0)
		stru->multi = 1;
	ft_skip(s, i, 0);
	if (s[*i] == '^')
	{
		*i = *i + 1;
		stru->exp += ft_skip(s, i, 1) * ft_atoi(s + *i);
		if (ft_isdigit(s[*i]) != 1)
			ft_put_error("parse error: after '^' ", 2, -1);
		while (s[*i] && ft_isdigit(s[*i]))
			*i = *i + 1;
	}
	else
		stru->exp += 1;
	return (0);
}

t_stru		*fill_stru(int *i, t_stru *stru, char *s)
{
	int		bol;
	int		mult;

	bol = 0;
	mult = 1;
	while (s[*i] != '\0' && ((s[*i] != '-' && s[*i] != '+') || mult == 1)
			&& s[*i] != '=')
	{
		stru->sign *= ft_skip(s, i, mult);
		if ((ft_isdigit(s[*i])) != 0)
			stru->multi = fill_multi(i, s, &bol, &mult);
		else if (s[*i] == '*' && (mult = 1))
			*i = *i + 1;
		else if (s[*i] == 'X' || s[*i] == 'x')
			mult = fill_exp(i, s, bol, stru);
		else
			ft_put_error("parse error: invalid char", 2, -1);
		ft_skip(s, i, 0);
	}
	if (mult == 1)
		ft_put_error("parse error: invalid format (eg: * =)", 2, -1);
	return (stru);
}

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
#include "libft.h"

void		parse(char *s)
{
	int i;
	t_list	*lst;
	t_stru*	stru;
	int	n;
	int		default_n;

	stru = (t_stru*)ft_strnew(sizeof(t_stru));
	i = 0;
	n = 1;
	default_n = 1;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 1 && s[i])
		{
			i++;
			continue;
		}
		if (s[i] == '+' && ++i)
			continue ;
		if (s[i] == '-' && ++i)
		{
			n = -1 * n;
			continue ;
		}
		if (s[i] == '=' && ++i)
		{
			if (default_n == -1)
				ft_put_error("WARNING : Two '=' signs in string", 1, -1);
			default_n = -1;
		}
		stru = fill_stru(&i, stru, n, s);
		ft_lstaddend((void*)&stru, sizeof(t_stru), &lst);
		ft_putnbr(stru->sign);
		ft_putendl("");
		ft_putnbr(stru->multi);
		ft_putendl("");
		ft_putnbr(stru->exp);
		ft_putendl("\n");
		if (s[i] == '=' && ++i)
		{
			if (default_n == -1)
				ft_put_error("WARNING : Two '=' signs in string", 1, -1);
			default_n = -1;
		}
		n = default_n;
	}
}

t_stru		*fill_stru(int *i, t_stru *stru, int sign, char *s)
{
	int	bol;
		//const void *content, size_t content_size, t_list **plst
		//ft_lstaddend(s[*i]);
		ft_bzero(stru, sizeof(t_stru));
		stru->sign = sign;
		bol = 0;
		while (s[*i] != '\0' && s[*i] != '-' && s[*i] != '+' && s[*i] != '=')
		{
			if (ft_isspace(s[*i]) == 1 && s[*i])
			{
				i++;
				continue;
			}
			if ((ft_isdigit(s[*i])) != 0)
			{
				bol = 1;
				stru->multi = ft_atoi(s + *i);
 				while (s[*i] && (ft_isdigit(s[*i]) != 0))
					i++;
				continue;
			}
			if (s[*i] == '*')
			{
				i++;
				continue;
			}
			if (s[*i] == 'X')
			{
				if (bol != 1 && stru->multi == 0)
					stru->multi = 1;
				stru->exp = 1;
		//		if (s[*i] && s[*i] == '^' && s[*i - 1] == 'X' && ft_isdigit(s[*i + 1]) != 0)
				if (s[*i] == '^')
				{
					i++;
					stru->exp = ft_atoi(s + *i);
					while (s[*i] && ft_isdigit(s[*i]))
						i++;
				}
			}
		}
		return (stru);
}
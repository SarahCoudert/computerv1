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

// static void test(t_list **lst)
// {
// 	t_list *ptr;

// 	ptr = *lst;
// 	while (ptr->next)
// 	{
// 		ft_putnbr((int)((t_stru*)(ptr->content))->multi);
// 		ft_putendl("");
// 		ft_putnbr(((t_stru*)(ptr->content))->sign);
// 		ft_putendl("");
// 		ft_putnbr(((t_stru*)(ptr->content))->exp);
// 		ft_putendl("\n");
// 		ptr = ptr->next;
// 	}
// }

void		parse(char *s)
{
	int i;
	int j;
	t_list	*lst;
	t_stru*	stru;

	stru = (t_stru*)ft_strnew(sizeof(t_stru));
	i = 0;
	j = 0;
	stru->sign = 1;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != '-' && s[i] != '+' && s[i] != '=')
	{	if (ft_isspace(s[i]) == 1 && s[i])
		{
			i++;
			continue;
		}
		if (s[i] == '-')
		{
			i++;
			stru->sign = -1;
			continue;
		}
		if ((ft_isdigit(s[i])) != 0)
		{
			stru->multi = ft_atoi(s + i);
			while ((ft_isdigit(s[i + j]) != 0))
				j++;
			i += j;
			j = 0;
			continue;
		}
		if (s[i] == '*')
		{
			i++;
			continue;
		}
		if (s[i] == 'X')
		{
			stru->exp = 1;
			i++;
	//		if (s[i] && s[i] == '^' && s[i - 1] == 'X' && ft_isdigit(s[i + 1]) != 0)
			if (s[i] == '^')
			{
				i++;
				stru->exp = ft_atoi(s + i);
				while (ft_isspace(s[i]) && ft_isdigit(s[i]))
					i++;
			}
		}
		if (s[i] && (s[i] == '*' || s[i] == '+' || s[i] == '-' ||
			s[i] == '='))
			i++;
		if (stru->sign != -1)
			stru->sign = 1;
	}
		ft_putnbr(stru->sign);
		ft_putendl("");
		ft_putnbr(stru->multi);
		ft_putendl("");
		ft_putnbr(stru->exp);
		ft_putendl("\n");
		ft_lstaddend((void*)&stru, sizeof(t_stru), &lst);
		ft_bzero(stru, sizeof(t_stru));
	}
	// test(&lst);
}

			//const void *content, size_t content_size, t_list **plst
			//ft_lstaddend(s[i]);

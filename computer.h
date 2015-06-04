#ifndef COMPUTER_H
# define COMPUTER_H

#include "libft/includes/libft.h"

#define STRU		((t_stru*)(list->content))
#define STRU_NEXT	((t_stru*)(list->next->content))

typedef struct		s_stru
{
	int				sign;
	double			multi;
	int				exp;
}					t_stru;

double			ft_atof(char *str, int *i);
t_list			*parse(char *s);
t_stru			*fill_stru(int *i, t_stru *stru, char *s);
int				ft_skip(char *s, int *i, int b);
t_list			*sort_list(t_list *list);
double			square_root(double n);
t_list			*add_list(t_list *list);
void			form_reduit(t_list *list);

#endif

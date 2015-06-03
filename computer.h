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

void			parse(char *s);
t_stru			*fill_stru(int *i, t_stru *stru, int sign, char *s);

#endif

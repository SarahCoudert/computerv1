/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 19:41:32 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/05 19:41:48 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTER_H
# define COMPUTER_H

# include "libft/includes/libft.h"
# include <stdio.h>
# define STRU		((t_stru*)(list->content))
# define STRU_NEXT	((t_stru*)(list->next->content))

typedef struct		s_stru
{
	int				sign;
	double			multi;
	int				exp;
}					t_stru;

void				solv(t_list *list);
double				ft_atof(char *str, int *i);
t_list				*parse(char *s);
t_stru				*fill_stru(int *i, t_stru *stru, char *s);
int					ft_skip(char *s, int *i, int b);
t_list				*sort_list(t_list *list);
double				square_root(double n);
t_list				*add_list(t_list *list);
void				form_reduit(t_list *list, int etape);
void				print_res(double a, double b, double delta, int i);

#endif

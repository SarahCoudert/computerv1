/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:03:30 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/03 20:14:41 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(char *str, int *i)
{
	double	nbr;
	double	vir;
	int		sign;
	int		t;

	sign = 1;
	nbr = 0.0;
	vir = 0.0;
	if (str[*i] == '-')
	{
		*i = *i + 1;
		sign = -1;
	}
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + str[*i] - '0';
		*i = *i + 1;
	}
	if (str[*i] == '.' || str[*i] == ',')
	{
		*i = *i + 1;
		t = 0;
		while (ft_isdigit(str[t + *i]) && t <= 7)
			t++;
		while (str[--t + *i] != ',' && str[t + *i] != '.')
		{
			vir = (vir / 10) + str[t + *i] - '0';
			*i = *i + 1;
		}
		vir = vir / 10;
	}
	return (sign * (nbr + vir));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:03:30 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/04 21:19:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


float		ft_atof(const char *str)
{
	float	n;
	int		i;
	int		k;
	int		signe;

	i = 0;
	n = 0;
	k = 0;
	signe = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	signe = (str[i] == '-') ? -signe : signe;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i++] - 48);
		if (str[i] == '.')
			k = i++;
	}
	while (k != 0 && str[++k])
		signe = signe * 10;
	return (n / signe);
}

// #include "computer.h"

// double		ft_atof(char *str, int *i)
// {
// 	double	nbr;
// 	double	vir;
// 	int		sign;
// 	int		t;

// 	sign = 1;
// 	nbr = 0.0;
// 	vir = 0.0;
// 	if (str[*i] == '-')
// 	{
// 		*i = *i + 1;
// 		sign = -1;
// 	}
// 	while (str[*i] != '\0' && ft_isdigit(str[*i]))
// 	{
// 		nbr = (nbr * 10) + str[*i] - '0';
// 		*i = *i + 1;
// 	}
// 	if (str[*i] == '.' || str[*i] == ',')
// 	{
// 		*i = *i + 1;
// 		t = *i;
// 		while (ft_isdigit(str[t + *i]) && t <= *i + 7)
// 			t++;
// 		while (str[--t] != ',' && str[t] != '.')
// 		{
// 			vir = (vir / 10) + str[t] - '0';
// 			*i = *i + 1;
// 		}
// 		vir = vir / 10;
// 		*i = *i + 1;
// 	}
// 	return (sign * (nbr + vir));
// }

// void	ft_putdouble(double nbr)
// {
// 	ft_putnbr(nbr);
// 	nbr = nbr - (nbr / 1);
// 	if (nbr < 1 && nbr > 0)
// 	{
// 			ft_putchar('.');
// 	}
// }
// /*
// void	ft_putdouble(double nbr)
// {
// 	int		t;
// 	int		v;

// 	v = 1;
// 	while (nbr / v >= 1)
// 		v = v * 10;
// 	while (nbr >= 1)
// 	{
// 		ft_putchar(nbr / v);
// 		v = v / 10;
// 		nbr = nbr / 10;
// 	}
// }*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 10:12:44 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/05 19:44:52 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		f(int nbr)
{
	int		n;

	if (nbr < 0)
	{
		printf("-1");
		nbr *= -1;
	}
	if (nbr == 0 || nbr == 1)
	{
		printf(nbr);
	}
	n = 2;
	while (nbr != 1 && nbr >= n)
	{
		if (nbr % n == 0)
		{
			printf(n);
			nbr = nbr / n;
		}
		else
			n++;
	}
}

int			pgcd(int c, int v)
{
	int		n;
	int		k;
	int		sign;

	sign = 1;
	if (c <= 0 && v <= 0)
		sign = -1;
	k = 1;
	n = 2;
	while (c >= n && v >= n)
	{
		if (v % n == 0 && c % n == 0)
		{
			k = n;
		}
		else
			n++;
	}
	return (sign * k);
}

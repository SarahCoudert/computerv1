/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 10:12:44 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/05 10:13:48 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**algo de la fonction d'affichage de tous les fprime
**(300 ==> 2 * 2 * 3 * 5 * 5)
** ce qui permet de montrer sqrt(150) == 5 * 2 * sqrt(3)
** VALABLE SEULEMENT POUR LES NOMBRES ENTIERS
** pgcd :
**trouve le plus grand commun diviseur (permet de  simplifier les fractions)
*/

void f(int nbr)
{
	int		n;

	if (nbr < 0)
	{
		print("-1");
		nbr *= -1;
	}
	if (nbr == 0 || nbr == 1)
	{
		print(nbr);
	}
	n = 2;
	while (nbr != 1 && nbr >= n)
	{
		if (nbr % n == 0)
		{
			print(n);
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

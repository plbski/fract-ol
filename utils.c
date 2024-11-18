/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:50:51 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/18 19:56:47 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>

double ft_fraction(char *s, int i, double fraction)
{
	double	diviseur;

	diviseur = 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		fraction = fraction * 10 + (s[i] - '0');
		diviseur *= 10;
		i ++;
	}
	return (fraction / diviseur);
}
double ft_atof(char *s)
{
	double	decimal;
	double	fraction;
	int	i ;
	double	p;
	double	diviseur;

	 p = 1;
	 decimal = 0;
	 diviseur = 1;
	 fraction = 0;
	 i  = 0;
	if (s[0] == '-') 
	{
		p *= -1;
		i ++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		decimal = decimal * 10 + (s[i] - '0');
		i ++;
	}
	if (s[i] == '.')
		fraction = ft_fraction(s, i + 1, 0);
	printf("%f \n", fraction);
	return(p *(decimal + fraction));
}

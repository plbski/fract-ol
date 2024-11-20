/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:50:51 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/20 11:13:11 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (2, &s[i], 1);
		i ++;
	}
}

void	msg_error(int i)
{
	ft_putstr("ERROR entrer des constante invalide");
	exit(i);
}

double	ft_fraction(char *s, int i, double fraction)
{
	double	diviseur;

	diviseur = 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		fraction = fraction * 10 + (s[i] - '0');
		diviseur *= 10;
		i ++;
	}
	if (s[i] != '\0')
		msg_error(0);
	return (fraction / diviseur);
}

double	ft_atof(char *s, double decimal, double fraction)
{
	int		i ;
	double	p;

	p = 1;
	i = 0;
	if (s[0] != '-' && s[0] != '+' && (s[i] < '0' && s[i] < '9'))
		msg_error(0);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
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
	return (p *(decimal + fraction));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (&s1[i] == &s2[i] && s1[i])
		i ++;
	return (s1[i] - s2[i]);
}

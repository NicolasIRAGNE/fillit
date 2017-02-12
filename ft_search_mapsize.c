/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_mapsize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:01:03 by niragne           #+#    #+#             */
/*   Updated: 2017/02/07 18:46:28 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

static int	ft_compare(int nbr, int *sqr)
{
	int	a;

	a = 11;
	while (sqr[a] >= nbr)
		a--;
	return (sqr[a + 1]);
}

static int	ft_sqrt(int x)
{
	int i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

int			ft_search_mapsize(char *str)
{
	int	a;
	int	i;
	int	nbr;
	int	sqr[11];

	i = -1;
	nbr = 0;
	a = -1;
	while (++a != 12)
		sqr[a] = a * a;
	while (str[++i])
		if (str[i] == '\n' && str[i + 1] == '\n')
			nbr++;
	nbr += 1;
	nbr *= 4;
	return (ft_sqrt(ft_compare(nbr, sqr)));
}

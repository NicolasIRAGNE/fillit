/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:03:17 by fdille            #+#    #+#             */
/*   Updated: 2017/02/16 16:52:10 by fdille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include "libft.h"

static int	ft_check_line(char *str)
{
	int		i;
	int		a;
	int		nbr;

	i = -1;
	a = 0;
	while (str[++i])
	{
		nbr = 0;
		if (a == 4 && str[i++])
			a = 0;
		while (str[i++] != '\n' && str[i])
			nbr++;
		a++;
		i--;
		if (nbr != 4 && a != 4)
			return (0);
	}
	return (1);
}

static int	ft_check_piece(char *str)
{
	int		i;
	int		a;
	int		nbr;

	i = -1;
	while (str[++i])
	{
		nbr = 0;
		a = 0;
		while (a < 5 && str[i])
		{
			if (str[i] == '#')
				nbr++;
			i++;
			if (str[i] == '\n')
				a++;
		}
		if (nbr != 4)
			return (0);
	}
	return (1);
}

static int	ft_check_bloc(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
	return (1);
}

static int	ft_check_contact(char *str)
{
	int		j;

	j = 0;
	while (*str)
	{
		if (*str == '#')
		{
			if (*(str + 1) == '#')
				j++;
			if (*(str - 1) == '#')
				j++;
			if (*(str + 5) == '#')
				j++;
			if (*(str - 5) == '#')
				j++;
		}
		if (*str == '\n' && *(str + 1) == '\n')
		{
			if (!(j % 6 == 0 || j % 8 == 0 || j % 7 == 0 || j % 9 == 0) || !j)
				return (0);
			j = 0;
		}
		str++;
	}
	return (((!(j % 6) || !(j % 8) || !(j % 7) || !(j % 9)) && !(j == 0)));
}

int			ft_checkfile(char *str)
{
	if (!ft_strlen(str))
		return (0);
	if (ft_check_line(str) == 0)
		return (0);
	if (ft_check_piece(str) == 0)
		return (0);
	if (ft_check_bloc(str) == 0)
		return (0);
	if (ft_check_contact(str) == 0)
		return (0);
	return (1);
}

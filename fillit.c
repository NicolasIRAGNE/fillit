/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdille <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:15:31 by fdille            #+#    #+#             */
/*   Updated: 2017/02/12 19:23:17 by fdille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		ft_put(t_usi *tetris, t_usi *map, int j, int k)
{
	map[j] |= ((*tetris & 0xf000)) >> k;
	map[j + 1] |= ((*tetris & 0x0f00) << 4) >> k;
	map[j + 2] |= ((*tetris & 0x00f0) << 8) >> k;
	map[j + 3] |= ((*tetris & 0x000f) << 12) >> k;
}

static void		ft_remove(t_usi *tetris, t_usi *map, int j, int k)
{
	map[j] ^= ((*tetris & 0xf000)) >> k;
	map[j + 1] ^= ((*tetris & 0x0f00) << 4) >> k;
	map[j + 2] ^= ((*tetris & 0x00f0) << 8) >> k;
	map[j + 3] ^= ((*tetris & 0x000f) << 12) >> k;
}

static int		ft_check(t_usi *tetris, t_usi *map, int j, int k)
{
	if (!(((*tetris & 0xf000)) >> k & map[j]) &&
			!(((*tetris & 0x0f00) << 4) >> k & map[j + 1]) &&
			!(((*tetris & 0x00f0) << 8) >> k & map[j + 2]) &&
			!(((*tetris & 0x000f) << 12) >> k & map[j + 3]))
		return (1);
	return (0);
}

int				fillit(t_usi *tetris, t_usi *map, int size)
{
	int j;
	int k;

	j = -1;
	if (!*tetris)
		return (1);
	while (++j < size)
	{
		k = 0;
		while (k < size)
		{
			if (ft_check(tetris, map, j, k))
			{
				ft_put(tetris, map, j, k);
				if (fillit(tetris + 1, map, size))
				{
					*tetris = ((j << 8) + k);
					return (1);
				}
				ft_remove(tetris, map, j, k);
			}
			k++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:44:03 by fdille            #+#    #+#             */
/*   Updated: 2017/02/12 17:42:40 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft.h"

t_usi		*create_map(int size)
{
	t_usi	*ret;
	int		i;
	int		j;
	int		flag;

	flag = 0;
	ret = malloc(sizeof(t_usi) * 16);
	i = 0;
	j = 0;
	while (i < size)
	{
		ret[i] = 0x8000 >> size;
		i++;
	}
	ret[i] = 0xffff;
	return (ret);
}

int			fillit(t_usi *tetris, t_usi *map, int size)
{
	int j;
	int k;

	j = 0;
	if (!*tetris)
		return (1);
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			if (!(((*tetris & 0xf000)) >> k & map[j]) &&
				!(((*tetris & 0x0f00) << 4) >> k & map[j + 1]) &&
				!(((*tetris & 0x00f0) << 8) >> k & map[j + 2]) &&
				!(((*tetris & 0x000f) << 12) >> k & map[j + 3]))
			{
				map[j] |= ((*tetris & 0xf000)) >> k;
				map[j + 1] |= ((*tetris & 0x0f00) << 4) >> k;
				map[j + 2] |= ((*tetris & 0x00f0) << 8) >> k;
				map[j + 3] |= ((*tetris & 0x000f) << 12) >> k;
				if (fillit(tetris + 1, map, size))
				{
					*tetris = ((j << 8) + k);
					return (1);
				}
				map[j] ^= ((*tetris & 0xf000)) >> k;
				map[j + 1] ^= ((*tetris & 0x0f00) << 4) >> k;
				map[j + 2] ^= ((*tetris & 0x00f0) << 8) >> k;
				map[j + 3] ^= ((*tetris & 0x000f) << 12) >> k;
			}
			k++;
		}
		j++;
	}
	return (0);
}

int			puterr(char *str)
{
	ft_putstr(str);
	return (0);
}

int			main(int ac, char **av)
{
	char		**dbl;
	t_usi		*tetris[2];
	t_usi		*tetrismap;
	int			size[2];
	char		*str;

	if (ac != 2)
		return (puterr("usage: fillit file\n"));
	if (!(str = ft_read_to_string(av[1])) || ft_checkfile(str) == 0)
		return (puterr("error\n"));
	size[0] = ft_search_mapsize(str);
	dbl = ft_strsplit(str, '\n');
	size[1] = ft_tablen(dbl) / 4;
	tetris[0] = get_tetris(dbl, size[1]);
	tetris[1] = get_tetris(dbl, size[1]);
	set_tetris(tetris[0], size[1]);
	set_tetris(tetris[1], size[1]);
	tetrismap = create_map(size[0]);
	while (!(fillit(tetris[0], tetrismap, size[0])))
	{
		size[0]++;
		tetrismap = create_map(size[0]);
	}
	ft_putsol(tetris[1], tetris[0], size[0]);
	return (0);
}

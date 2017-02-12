/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:35:48 by niragne           #+#    #+#             */
/*   Updated: 2017/02/12 15:47:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_usi		*get_tetris(char **file, size_t len)
{
	int		i;
	t_usi	*ret;

	i = 0;
	ret = (t_usi*)malloc(sizeof(t_usi) * len + 1);
	while (file[i])
	{
		ret[i >> 2] <<= 4;
		if (file[i][0] == '#')
			ret[i >> 2] += 8;
		if (file[i][1] == '#')
			ret[i >> 2] += 4;
		if (file[i][2] == '#')
			ret[i >> 2] += 2;
		if (file[i][3] == '#')
			ret[i >> 2] += 1;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

t_usi		*set_tetris(t_usi *tetris, size_t len)
{
	size_t	i;
	t_usi	*ret;

	i = 0;
	ret = malloc(sizeof(t_usi) * len + 1);
	while (i < len)
	{
		while (!(tetris[i] & 0x8888))
			tetris[i] <<= 1;
		while (!(tetris[i] & 0xf000))
			tetris[i] <<= 4;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

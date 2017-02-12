/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:20:15 by niragne           #+#    #+#             */
/*   Updated: 2017/02/11 18:50:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "libft.h"

static void	setup(char **str, int size)
{
	*str = malloc((size + 1) * (size + 1) + 1);
	ft_memset(*str, '.', size * (size + 1) + 1);
	(*str)[size * (size + 1)] = '\0';
}

static void	cut(char *str, int size)
{
	int i;

	i = -1;
	while (str[(size + 1) * ++i])
		str[(size + 1) * i + size] = '\n';
	ft_putstr(str);
}

void		ft_putsol(t_usi *tetris, t_usi *pos, int t)
{
	char	*str;
	char	c;
	t_usi	j;
	int		k;

	c = 'A';
	setup(&str, t);
	while (*tetris)
	{
		k = 0;
		j = 0x8000;
		while (j > 0)
		{
			if (*tetris & j)
			{
				str[((*pos >> 8) + k / 4) * (t + 1) + (*pos & 0xf) + k % 4] = c;
			}
			j >>= 1;
			k++;
		}
		pos++;
		tetris++;
		c++;
	}
	cut(str, t);
}

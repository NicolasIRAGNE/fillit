/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:01:03 by fdille            #+#    #+#             */
/*   Updated: 2017/02/12 15:54:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft.h"

static char	*ft_spedup(char *src)
{
	int		i;
	int		j;
	char	*s2;

	if (!src)
		return (0);
	i = ft_strlen(src);
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	j = 0;
	while (j < i)
	{
		s2[j] = src[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

static char	*ft_concat(char *dest, char *src)
{
	size_t index;
	size_t index2;

	index = 0;
	index2 = ft_strlen(dest);
	while (index <= ft_strlen(src))
	{
		dest[index2] = src[index];
		index++;
		index2++;
	}
	return (dest);
}

char		*ft_read_to_string(char *argv)
{
	char	*str;
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];

	fd = open(argv, O_RDONLY);
	if (!fd)
		return (NULL);
	str = (char*)malloc(sizeof(char) * BUFF_SIZE);
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_spedup(ft_concat(str, buf));
	}
	if (close(fd) == -1 || ret == -1)
		return (NULL);
	return (str);
}

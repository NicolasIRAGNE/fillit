/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:14:57 by fdille            #+#    #+#             */
/*   Updated: 2017/02/12 19:18:28 by fdille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef unsigned short int	t_usi;

int							ft_checkfile(char *str);
char						*ft_read_to_string(char *argv);
int							ft_search_mapsize(char *str);
t_usi						*get_tetris(char **file, size_t len);
t_usi						*set_tetris(t_usi *tetris, size_t len);
void						ft_putsol(t_usi *tetris, t_usi *pos, int size);
int							fillit(t_usi *tetris, t_usi *map, int size);

#endif

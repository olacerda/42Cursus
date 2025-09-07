/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:54:15 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/07 08:39:10 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_gameinfo
{
	char	**map;
	char	*map_name;
	char	*map_adress;
	int		total_lines;
	int		line_len;
}	t_gameinfo;

typedef struct s_playerinfo
{
	int	line;
	int	column;
}	t_playerinfo;

typedef struct s_mapinfo
{
	char	*elements;
	int		*count_elements;
}	t_mapinfo;

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/utils.h"



void 	so_long(t_gameinfo *s_game);
char	*get_map_adress(char *chosen_map);
int		count_lines(char *chosen_map);
char 	**create_map(t_gameinfo *s_game);

#endif
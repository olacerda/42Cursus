/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:32:16 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/07 09:17:29 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_rectangle(t_gameinfo *s_game)
{
	int	line_1_size;
	int	line_size;
	int	line;

	line = 0;
	if (!(*s_game->map) || !s_game->map)
		return (0);
	line_1_size = strlength(s_game->map[line++]);
	printf("\n\nCHECK RECTANGLE\n\nmap1len: %d\n", line_1_size);
	while (line < s_game->total_lines|| s_game->map[line] != NULL)
	{
		line_size = strlength(s_game->map[line]);
		printf("mapslens: %d\n", line_size);
		if (line_size != line_1_size)
			return (0);
		line++;
	}
	s_game->line_len = line_1_size;
	printf("\nLine_Len %d\n", s_game->line_len);
	return (1);
}

int	check_close_walls(t_gameinfo *s_game)
{
	int	line;
	int	index;

	index = 0;
	line = 0;
	if (!s_game->map || !(s_game->map[index]))
		return (0);
	while(s_game->map[line][index] && s_game->map[line][index] != '\n')
	{
		if(s_game->map[line][index++] != '1')
			return (0);
		if (line == 0 && (s_game->map[line][index] == '\n' || !s_game->map[line][index]))
		{
			index = 0;
			line = (s_game->total_lines - 1);
		}
	}
	line = 1;
	while(s_game->map[line] != NULL)
	{
		if ((s_game->map[line][0] != '1') || (s_game->map[line][s_game->line_len - 1] != '1'))
			return (0);
		line++;		
	}
	return (1);
}

void create_elements(t_mapinfo *s_map)
{
	char	*elements;
	int		*count_elements;

	elements = malloc(7 * sizeof(char));
	if (!elements)
		return ;
	count_elements = malloc(6 * (sizeof(int)));
	if (!count_elements)
		return;
	elements[0] = 'P';
	elements[1] = 'E';
	elements[2] = 'C';
	elements[3] = '1';
	elements[4] = '0';
	elements[5] = 'O';
	elements[6] = '\0';
	s_map->elements = elements;
	count_elements[0] = 0;
	count_elements[1] = 0;
	count_elements[2] = 0;
	count_elements[3] = 0;
	count_elements[4] = 0;
	count_elements[5] = 0;
	count_elements[6] = 0;
	s_map->count_elements = count_elements;
}

void	count_elements(t_gameinfo *s_game, t_playerinfo *s_play, t_mapinfo *s_map)
{
	int	line;
	int	column;
	int	index;

	line = -1;
	while (s_game->map[++line] != NULL)
	{
		column = -1;
		while ((s_game->map[line][++column]) && s_game->map[line][column] != '\n')
		{
			if (s_game->map[line][column] == 'P')
				*s_play = (t_playerinfo){line, column};
			index = 0;
			while ((s_game->map[line][column] != s_map->elements[index]) 
				&& (s_map->elements[index] != 'O'))
				index++;
			s_map->count_elements[index]++;
		}
	}
}

int	check_elements(t_gameinfo *s_game, t_playerinfo *s_play, t_mapinfo *s_map)
{
	int	index;

	index = 0;
	create_elements(s_map);
	count_elements(s_game, s_play, s_map);
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("%d\n", s_map->count_elements[i]);
		i++;
	}
	while(s_map->elements[index] != '\0')
	{
		if ((s_map->elements[index] == 'P' || s_map->elements[index] == 'E') 
			&& s_map->count_elements[index] > 1)
			return (0);
		if (s_map->elements[index] == 'C' && s_map->count_elements[index] < 1)
			return (0);
		if (s_map->elements[index] == 'O' && s_map->count_elements[index] > 0)
			return (0);
		index++;
	}
	return (1);
}

int	clear_path(char **map, int	line, int column, int *colectables)
{
	if ((column == 0) || line == 0 || map[line] == NULL || 
		map[line][column] == '\n' || map[line][column] == '\0')
		return (0);
	if (map[line][column] == 'C')
	{
		(*colectables)--;
		if (*colectables == 0)
			return (1);
	}
	if (map[line][column] == '1' || 
		map[line][column] == 'E')
		return (0);
	map[line][column] = '1';
	if(clear_path(map, line + 1, column, colectables) == 1)
		return (1);
	if(clear_path(map, line, column + 1, colectables) == 1)
		return (1);
	if(clear_path(map, line - 1, column, colectables) == 1)
		return (1);
	if(clear_path(map, line, column - 1, colectables) == 1)
		return (1);
	return (0);
}

int	check_clear_path(t_gameinfo *s_game, t_playerinfo *s_play, t_mapinfo *s_map)
{
	// char **map;
	int	line;
	int	column;
	int	path;
	int	colectables;

	colectables = s_map->count_elements[2];
	line = s_play->line;
	column = s_play->column;
	printf("\nplayer position:\n\n\nLine: %d\nColumn: %d\n\n\n", s_play->line, s_play->column);
	// map = create_map(s_game);
	printf("\nNOVO BOROGODOOOOOOOOOO\n\n\nLine: %d\nColumn: %d\n\n\n", s_play->line, s_play->column);
	path = clear_path(s_game->map, line, column, &colectables);
	return (path);
}


int	check_file_name(t_gameinfo *s_game)
{
	char	*file_type;
	int		ftype_index;
	int		index;
	int		teste;

	index = 0;
	ftype_index = 0;
	file_type = ".ber";
	if (!s_game->map_name || !s_game)
		return (0);
	// printf("file type: %s\n\n", file_type);
	while (s_game->map_name[index] != '\0')
	{
		// printf("file name: %c\n", s_game->map_name[index]);
		index++;
	}
	// printf("\nFile name size: %d", index);
	if (index < 5)
		return (0);
	// printf("\nPASSOU\n\n");
	index -= 4;
	teste = index;
	while (s_game->map_name[teste] != '\0')
	{
		// printf("file modificado: %c\n", s_game->map_name[teste]);
		teste++;
	}
	// printf("\nIndex pos -4: %d", index);
	while ((file_type[ftype_index] == s_game->map_name[index]) && (file_type[ftype_index]))
	{
		ftype_index++;
		index++;
	}
	// printf("\nIndex pos while: %d", index);
	if (file_type[ftype_index] == '\0')
		return (1);
	return (0);
}
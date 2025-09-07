/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:04:33 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/07 21:09:15 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *chosen_map)
{
	int	fd;
	int	count;
	char	*string;

	count = 0;
	fd = open(chosen_map, O_RDONLY);
	if (fd < 0)
		return (0);
	string = "";
	while(string != NULL)
	{
		string = getnextline(fd);
		if (string != NULL)
			count++;
		free(string);
	}
	close(fd);
	return (count);
}

char	*get_map_adress(char *chosen_map)
{
	char *adress;
	int	map_len;
	int	index;
	int	ad_index;

	if (!chosen_map)
		return (NULL);
	index = 0;
	ad_index = 0;
	map_len = strlength(chosen_map);
	adress = malloc((map_len + 6) * sizeof(char));
	if (!adress)
		return (NULL);
	adress[ad_index++] = 'm';
	adress[ad_index++] = 'a';
	adress[ad_index++] = 'p';
	adress[ad_index++] = 's';
	adress[ad_index++] = '/';
	while (chosen_map[index] != '\0')
	{
		adress[ad_index] = chosen_map[index];
		ad_index++;
		index++;
	}
	adress[ad_index] = '\0';
	// printf("Map adress in function: %s\n", adress);
	return (adress);
}

char **create_map(t_gameinfo *s_game)
{
	char	**map;
	int		line;
	int		fd;

	// printf("\nentrou no create_map\n");
	fd = open(s_game->map_adress, O_RDONLY);
	if (fd < 0)
		return (NULL);
	write(1, "passou", 6);
	// printf("\n LINES %d\n", s_game->total_lines);
	map = malloc ((s_game->total_lines + 1) * sizeof(char *));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	line = 0;
	while(line < s_game->total_lines)
		map[line++] = getnextline(fd);
	map[line] = NULL;
	close(fd);
	return (map);
}

void	so_long(t_gameinfo *s_game)
{
	int		count = 0;

	if (!s_game->map)
		return ;
	while (s_game->map[count] != NULL)
	{
		printf("%s\n", s_game->map[count]);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	t_gameinfo 		*s_game = malloc(sizeof(t_gameinfo));
	t_playerinfo	*s_play = malloc(sizeof(t_playerinfo));
	t_mapinfo		*s_map = malloc(sizeof(t_mapinfo));
	int				check_name;
	int				fd;

	if (argc != 2)
		return (1);
	s_game->map_name = argv[1];
	check_name = check_file_name(s_game);
	printf("\nCheck file name: %d\n", check_name);
	if (!check_name)
	{
		write(1, "rodou", 5);
		return (1);
	}
	*s_game = (t_gameinfo){0, 0, 0, 0, 0};
	*s_play = (t_playerinfo){0, 0};
	*s_map = (t_mapinfo){0, 0};
	s_game->map_adress = get_map_adress(argv[1]);
	printf("\nMap adress: %s\n", s_game->map_adress);
	s_game->total_lines = count_lines(s_game->map_adress);
	printf("\nTotal lines: %d\n", s_game->total_lines);
	s_game->map = create_map(s_game);
	so_long(s_game);
	printf("\nCheck rectangle: %d\n", check_rectangle(s_game));
	printf("\nCheck close walls: %d\n", check_close_walls(s_game));
	printf("\nCheck Player/Colectabels/Exit: %d\n", check_elements(s_game, s_play, s_map));
	printf("\nCheck clear path: %d\n", check_clear_path(s_game, s_play, s_map));
	printf("\nCheck file name: %d\n", check_name);
	free(s_game);
	free(s_play);
	free(s_map);
	fd = open(s_game->map_adress, O_RDONLY);
	printf("New FD: %d\n", fd);
}
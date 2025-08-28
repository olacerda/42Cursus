/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:44:26 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/24 23:57:15 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new(char **line, char *buff, int *x, int *endall)
{
	char	*newline;
	int		index;

	if (x[READBYTES] <= 0)
		return ;
	if (x[START] >= x[READBYTES])
		*(long *)x = 0;
	while (buff[x[END]] != '\n' && x[END] < x[READBYTES] && ++(x[END]))
		(*endall)++;
	newline = malloc(((*endall) + 1 + (buff[(x[END])] == '\n')) * sizeof(char));
	if (!newline)
		return ;
	index = -1;
	while (++index < (*endall - x[END]))
		newline[index] = (*line)[index];
	while (x[START] <= (x[END]) && x[START] < x[READBYTES])
		newline[index++] = buff[(x[START])++];
	newline[index] = '\0';
	free(*line);
	*line = newline;
}

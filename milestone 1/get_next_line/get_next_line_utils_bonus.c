/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:25 by otlacerd          #+#    #+#             */
/*   Updated: 2025/06/24 23:48:29 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	liner(char **ln, t_g *x, int *endtotal)
{
	char	*newline;
	int		index;

	if (x->readbytes <= 0)
		return ;
	if (x->start >= x->readbytes)
		*(long *)x = 0;
	while ((x->buff[x->end] != '\n') && (x->end < x->readbytes) && ++(x->end))
		(*endtotal)++;
	newline = malloc(*endtotal + 1 + (x->buff[x->end] == '\n') * sizeof(char));
	if (!newline)
		return ;
	index = -1;
	while (++index < (*endtotal - x->end) && *ln)
		newline[index] = (*ln)[index];
	while ((x->start <= x->end) && (x->start < x->readbytes))
		newline[index++] = x->buff[x->start++];
	newline[index] = '\0';
	free(*ln);
	*ln = newline;
}

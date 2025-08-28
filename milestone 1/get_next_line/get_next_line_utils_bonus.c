/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:25 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/27 10:45:08 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line_bonus.h"

char	*liner(char **ln, t_g *x, int *endtotal)
{
	char	*newline;
	int		index;

	if (x->readbytes <= 0)
		return (free(*ln), NULL);
	if (x->start >= x->readbytes)
		*(long *)x = 0;
	while ((x->buff[x->end] != '\n') && (x->end < x->readbytes) && ++(x->end))
		(*endtotal)++;
	newline = malloc(*endtotal + 1 + (x->buff[x->end] == '\n') * sizeof(char));
	if (!newline)
		return (NULL);
	index = -1;
	while (++index < (*endtotal - x->end) && *ln)
		newline[index] = (*ln)[index];
	while ((x->start <= x->end) && (x->start < x->readbytes))
		newline[index++] = x->buff[x->start++];
	return (newline[index] = '\0', free(*ln), newline);
}

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:25 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/27 10:57:47 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "asdasdasd.h"

char	*liner(t_g *x)
{
	char	*newline;
	int		index;

	if (x->readbytes <= 0)
		return (free(x->ln), NULL);
	while ((x->buff[0][x->end] != '\n') && (x->end < x->readbytes) && ++(x->end))
		(x->endtotal)++;
	newline = malloc(x->endtotal + 1 + (x->buff[0][x->end] == '\n') * sizeof(char));
	if ((index = -1) && (!newline))
		return (NULL);
	while (++index < (x->endtotal - x->end) && x->ln)
		newline[index] = (x->ln)[index];
	while ((x->start <= x->end) && (x->start < x->readbytes))
		newline[index++] = x->buff[0][x->start++];
	return (newline[index] = '\0', free(x->ln), newline);
}
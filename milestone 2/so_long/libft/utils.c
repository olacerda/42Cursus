/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:37:53 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/07 05:39:24 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	strlength(char *string)
{
	int	length;

	if (!string)
		return (0);
	length = 0;
	while(string[length] != '\0' && string[length] != '\n')
		length++;
	return (length);
}

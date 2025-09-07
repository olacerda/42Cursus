/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:03:08 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/03 21:05:51 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *string = malloc(3);

	string[0] = 'o';
	string[1] = 'i';
	string[3] = '\0';
	printf("\n\n%s\n\n", string);
	free(string);
	free(NULL);
	free(0);
}
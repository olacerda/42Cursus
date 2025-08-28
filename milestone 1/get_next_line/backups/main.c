/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:54:11 by olacerda          #+#    #+#             */
/*   Updated: 2025/06/20 08:00:23 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    char *linha;

    while ((linha = get_next_line(0)) != NULL)
    {
        printf("LIDO-> %s", linha);
        free(linha);
    }

    return 0;
}
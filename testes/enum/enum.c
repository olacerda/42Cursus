/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:28:51 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/03 20:36:46 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

typedef enum day
{
	segunda,
	terca,
	quarta,
	quinta,
	sexta,
	sabado,
	domingo,
}		day;

void	exercicio(void)
{
	day	today;
	int	monthday;

	monthday = 0;
	today = 0;
	while (monthday <= 30)
	{
		today = 0;
		while (today < 7 && (monthday + today <= 31))
		{
			printf("Dia do mes: %d\n", today + monthday);
			switch (today)
			{
			case segunda:
			case terca:
			case quarta:
			case quinta:
			case sexta:
			{
				printf("Dia util\n\n");
				break ;
			}
			case sabado:
			case domingo:
			{
				printf("Fim de semana\n\n");
				break ;
			}
			default:
				printf("Nenhum dia valido");
				break ;
			}
			today++;
		}
		monthday += today;
	}
}

int	main(void)
{
	exercicio();
}
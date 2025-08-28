/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:38:18 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/27 10:48:17 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_BUFFERSIZE
#  define MAX_BUFFERSIZE 4000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/select.h>	

typedef struct s_g
{
	int		start;
	int		end;
	int		readbytes;
	char	buff[BUFFER_SIZE];
}	t_g;

char	*get_next_line(int fd);
char	*liner(char **ln, t_g *x, int *endtotal);

#endif

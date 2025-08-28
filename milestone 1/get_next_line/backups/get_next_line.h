/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:06:49 by olacerda          #+#    #+#             */
/*   Updated: 2025/08/28 10:23:56 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	int		start;
	int		end;
	int		readbytes;
	char	buff[BUFFER_SIZE];
} t_gnl;

int    liner(char **line, t_gnl *st, int *endtotal);
char 	*get_next_line(int fd);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#endif
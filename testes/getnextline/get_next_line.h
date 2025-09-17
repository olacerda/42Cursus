/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:16:03 by otlacerd          #+#    #+#             */
/*   Updated: 2025/09/14 00:55:47 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# ifndef MAX
#  define MAX 4000000
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/select.h>
# include <unistd.h>

typedef struct s_g
{
	char	buff[BUFFER_SIZE + 1];
	int		rbts;
	int		start;
	int		end;
	char	*nline;
	int		totalend;
	char	*line;
	int		index;
}			t_g;

typedef struct s_w
{
	int		end;
	char	*nline;
	int		tend;
	char	*line;
	int		index;
}			t_w;

typedef struct s_z
{
	char	*line;
	int		index;
}			t_z;

char		*get_next_line(int fd);

#endif

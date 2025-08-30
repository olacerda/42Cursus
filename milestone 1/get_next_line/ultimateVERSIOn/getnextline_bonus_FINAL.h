/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline_bonus_FINAL.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:38:18 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/30 18:55:31 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAX
#  define MAX 4000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/select.h>

typedef struct s_g
{
	char	*line;
	int		i;
	int		t;
	int		s; 
	int		e;
	int		rb;
	char	b[BUFFER_SIZE];
	char	*n;
}	t_g;

typedef struct s_z
{
	char	*string;
	int		index;
	int		tend;
	int		s;
} t_z;

typedef struct s_y
{
	char	*string;
	int		index;
} t_y;

char	*get_next_line(int fd);

#endif

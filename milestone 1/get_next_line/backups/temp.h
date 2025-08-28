/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:38:18 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/28 11:29:45 by olacerda         ###   ########.fr       */
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
	int		sta;
	int		end;
	int		tot;
	int		byt;
	char	*ln;
	char	tmp[BUFFER_SIZE];
	char	(*buf2)[BUFFER_SIZE];
	char	(*buf)[BUFFER_SIZE];
	int		idx;
	char	*nln;
}	t_g;

char	*get_next_line(int fd);
char	*liner(t_g *x);

#endif

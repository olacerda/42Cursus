#ifndef MYVECTOR_H
# define MYVECTOR_H

typedef struct s_vec t_vec;

struct s_vec
{
	int	size;
	void (*add)(t_vec *this, int value);
	int	 (*get)(t_vec *this, int index);
	void (*map)(t_vec *this, void (*func)(int value));
};

typedef struct s_vec_p t_vec_p;

struct s_vec_p
{
	int	size;
	void (*add)(t_vec_p *this, int value);
	int (*get)(t_vec_p *this, int index);
	void (*map)(t_vec_p *this, void (*func)(int value));
	int	bufferadd;
	int	buffer;
	int	*arr;
};


# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#endif
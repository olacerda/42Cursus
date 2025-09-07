/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:40:55 by otlacerd          #+#    #+#             */
/*   Updated: 2025/08/25 22:49:21 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	add(t_vec_p *this,  int value)
{
	if (this->size >= this->buffer)
	{
		int *newarray;
		int	index;
		this->buffer += 10;
		newarray = malloc ((this->buffer + this->bufferadd) * sizeof(int));
		if (!newarray)
			return ;
		index = -1;
		while(this->arr[++index] < this->size)
			newarray[index] = this->arr[index];
		this->arr = newarray;
	}
	this->arr[this->size++] = value;
}

int	get(t_vec_p *this,  int index)
{
	return this->arr[index];
}

void	map(t_vec_p *this, void (*func)(int value))
{
	int	index;

	index = 0;
	while(index < this->size)
	{
		func(this->arr[index]);
		index++;
	}
}

t_vec *new_vector(){
	t_vec_p *t;

	t = malloc(sizeof(t_vec_p));
	t->add = add;
	t->size = 0;
	t->get = get;
	t->bufferadd = 10;
	t->arr = malloc (t->bufferadd * sizeof(int));
	t->map = map;
	return ((t_vec *)t);
}

void teste(int	a)
{
	printf("%d\n", a);
}

int main(){
	
	t_vec *v = new_vector();

	v->add(v, 1);
	v->add(v, 2);
	v->add(v, 3);
	v->add(v, 4);
	
	printf("get: %d\n", v->get(v, 1));
	// while(index < v->size)
	// {
	// 	printf("%d\n", v->arr[index]);
	// 	index++;
	// }
	v->map(v, teste);
}
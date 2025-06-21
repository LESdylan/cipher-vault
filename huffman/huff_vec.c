/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:47:01 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:47:51 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"
#include <stdlib.h>

t_vec	*create_vec(size_t capacity)
{
	t_vec	*vec;

	vec = (t_vec *)malloc(sizeof(t_vec));
	if (!vec)
		return (NULL);
	vec->data = (t_leaf **)malloc(capacity * sizeof(t_leaf *));
	if (!vec->data)
	{
		free(vec);
		return (NULL);
	}
	vec->size = 0;
	vec->capacity = capacity;
	return (vec);
}

static void	heapify_up(t_vec *vec, size_t i)
{
	t_leaf	*tmp;
	size_t	parent;

	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (vec->data[parent]->freq <= vec->data[i]->freq)
			break ;
		tmp = vec->data[parent];
		vec->data[parent] = vec->data[i];
		vec->data[i] = tmp;
		i = parent;
	}
}

void	push_vec(t_vec *vec, t_leaf *leaf)
{
	size_t		i;
	t_leaf		**new_data;

	if (vec->size >= vec->capacity)
	{
		vec->capacity *= 2;
		new_data = (t_leaf **)realloc(vec->data,
				vec->capacity * sizeof(t_leaf *));
		if (!new_data)
			return ;
		vec->data = new_data;
	}
	i = vec->size++;
	vec->data[i] = leaf;
	heapify_up(vec, i);
}

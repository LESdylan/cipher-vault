/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:45:00 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 17:45:00 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"
#include <stdlib.h>
#include <string.h>

void	heapify_down(t_vec *vec, size_t i)
{
	size_t	left;
	size_t	right;
	size_t	smallest;
	t_leaf	*tmp;

	while (1)
	{
		left = 2 * i + 1;
		right = 2 * i + 2;
		smallest = i;
		if (left < vec->size
			&& vec->data[left]->freq < vec->data[smallest]->freq)
			smallest = left;
		if (right < vec->size
			&& vec->data[right]->freq < vec->data[smallest]->freq)
			smallest = right;
		if (smallest == i)
			break ;
		tmp = vec->data[i];
		vec->data[i] = vec->data[smallest];
		vec->data[smallest] = tmp;
		i = smallest;
	}
}

t_leaf	*pop_vec(t_vec *vec)
{
	t_leaf	*min;

	if (vec->size == 0)
		return (NULL);
	min = vec->data[0];
	vec->data[0] = vec->data[--vec->size];
	heapify_down(vec, 0);
	return (min);
}

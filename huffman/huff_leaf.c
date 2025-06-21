/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff_leaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:45:37 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:46:53 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"

t_leaf	*create_leaf(unsigned char data, unsigned int freq)
{
	t_leaf	*leaf;

	leaf = (t_leaf *)malloc(sizeof(t_leaf));
	if (!leaf)
		return (NULL);
	leaf->data = data;
	leaf->freq = freq;
	leaf->left = NULL;
	leaf->right = NULL;
	return (leaf);
}

t_code	*find_code(t_code *table, int n, char ch)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (table[i].ch == ch)
			return (&table[i]);
		i++;
	}
	return (NULL);
}

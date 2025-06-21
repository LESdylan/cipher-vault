/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff_encode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:30:00 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:30:00 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"
#include <string.h>

t_leaf	*merge_nodes(t_leaf *l, t_leaf *r)
{
	t_leaf	*parent;

	parent = create_leaf('\0', l->freq + r->freq);
	parent->left = l;
	parent->right = r;
	return (parent);
}

void	encode(const char *input, t_code *table, int n, char *out)
{
	int		i;
	t_code	*code;

	out[0] = '\0';
	i = 0;
	while (input[i])
	{
		code = find_code(table, n, input[i]);
		if (code)
			strcat(out, code->code);
		i++;
	}
}

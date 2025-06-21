/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:30:00 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:30:00 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	pre_order(t_leaf *root, char *code, int depth)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
	{
		code[depth] = '\0';
		printf("%c: %s\n", root->data, code);
		return ;
	}
	if (root->left)
	{
		code[depth] = '0';
		pre_order(root->left, code, depth + 1);
	}
	if (root->right)
	{
		code[depth] = '1';
		pre_order(root->right, code, depth + 1);
	}
}

void	decode_single_char(t_leaf *root, const char *encoded)
{
	int	len;
	int	i;

	len = (int)strlen(encoded);
	i = 0;
	while (i < len)
	{
		printf("%c", root->data);
		i++;
	}
	printf("\n");
}

void	process_encoded_char(t_leaf **curr, t_leaf *root, char c)
{
	if (c == '0')
		*curr = (*curr)->left;
	else if (c == '1')
		*curr = (*curr)->right;
}

static void	decode_loop(t_leaf *root, const char *encoded)
{
	int		i;
	t_leaf	*curr;

	curr = root;
	i = 0;
	while (encoded[i] != '\0')
	{
		process_encoded_char(&curr, root, encoded[i]);
		if (encoded[i] != '0' && encoded[i] != '1')
		{
			i++;
			continue ;
		}
		if (curr && !curr->left && !curr->right)
		{
			printf("%c", curr->data);
			curr = root;
		}
		i++;
	}
	printf("\n");
}

void	decode(t_leaf *root, const char *encoded)
{
	if (root && !root->left && !root->right)
	{
		decode_single_char(root, encoded);
		return ;
	}
	decode_loop(root, encoded);
}

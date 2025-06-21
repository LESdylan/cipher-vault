/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:45:50 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:40:23 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_leaf	*build_huffman(const char *s, const int *freq, int n)
{
	t_vec	*heap;
	int		i;
	t_leaf	*l;
	t_leaf	*r;
	t_leaf	*root;

	heap = create_vec(n);
	i = -1;
	while (++i < n)
		push_vec(heap, create_leaf(s[i], freq[i]));
	while (heap->size > 1)
	{
		l = pop_vec(heap);
		r = pop_vec(heap);
		push_vec(heap, merge_nodes(l, r));
	}
	root = pop_vec(heap);
	return (free(heap->data), free(heap), root);
}

void	handle_leaf_code(t_huff_ctx *ctx, t_leaf *root, int depth)
{
	if (depth == 0)
	{
		ctx->code[0] = '0';
		ctx->code[1] = '\0';
	}
	else
		ctx->code[depth] = '\0';
	ctx->table[ctx->idx].ch = root->data;
	strcpy(ctx->table[ctx->idx].code, ctx->code);
	ctx->idx++;
}

void	build_code_table(t_huff_ctx *ctx, t_leaf *root, int depth)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
	{
		handle_leaf_code(ctx, root, depth);
		return ;
	}
	if (root->left)
	{
		ctx->code[depth] = '0';
		build_code_table(ctx, root->left, depth + 1);
	}
	if (root->right)
	{
		ctx->code[depth] = '1';
		build_code_table(ctx, root->right, depth + 1);
	}
}

void	count_frequencies(t_huff_ctx *ctx)
{
	initialize_freq_array(ctx->freq);
	calculate_char_freq(ctx->input, ctx->freq);
	build_char_arrays(ctx->freq, ctx->chars, ctx->f, &ctx->n);
}

void	process_huffman(t_huff_ctx *ctx)
{
	ctx->root = build_huffman(ctx->chars, ctx->f, ctx->n);
	pre_order(ctx->root, ctx->code, 0);
	ctx->idx = 0;
	build_code_table(ctx, ctx->root, 0);
	encode(ctx->input, ctx->table, ctx->idx, ctx->encoded);
	printf("Encoded: %s\n", ctx->encoded);
	printf("Decoded: ");
	decode(ctx->root, ctx->encoded);
}

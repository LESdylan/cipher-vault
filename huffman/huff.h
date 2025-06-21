/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:40:00 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:46:53 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUFF_H
# define HUFF_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct s_leaf
{
	unsigned char	data;
	unsigned int	freq;
	struct s_leaf	*left;
	struct s_leaf	*right;
} t_leaf;

typedef struct s_vec
{
	t_leaf		**data;
	size_t		size;
	size_t		capacity;
} t_vec;

typedef struct s_code
{
	char	ch;
	char	code[100];
} t_code;

typedef struct s_huff_ctx
{
	char	*input;
	int	freq[256];
	char	chars[256];
	int	f[256];
	int	n;
	t_leaf	*root;
	char	code[100];
	t_code	table[256];
	int	idx;
	char	encoded[10000];
} t_huff_ctx;

t_vec	*create_vec(size_t capacity);
void	push_vec(t_vec *vec, t_leaf *leaf);
void	heapify_down(t_vec *vec, size_t i);
t_leaf	*pop_vec(t_vec *vec);
t_leaf	*create_leaf(unsigned char data, unsigned int freq);
void	pre_order(t_leaf *root, char *code, int depth);
void	decode_single_char(t_leaf *root, const char *encoded);
void	process_encoded_char(t_leaf **curr, t_leaf *root, char c);
void	decode(t_leaf *root, const char *encoded);
t_leaf	*merge_nodes(t_leaf *l, t_leaf *r);
t_leaf	*build_huffman(const char *s, const int *freq, int n);
void	handle_leaf_code(t_huff_ctx *ctx, t_leaf *root, int depth);
void	build_code_table(t_huff_ctx *ctx, t_leaf *root, int depth);
void	initialize_freq_array(int *freq);
void	calculate_char_freq(char *s, int *freq);
void	build_char_arrays(int *freq, char *chars, int *f, int *n);
void	count_frequencies(t_huff_ctx *ctx);
void	process_huffman(t_huff_ctx *ctx);
t_code	*find_code(t_code *table, int n, char ch);
void	encode(const char *input, t_code *table, int n, char *out);

#endif

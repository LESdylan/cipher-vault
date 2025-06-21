/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:20:31 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:39:50 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"

int	main(int argc, char **argv)
{
	t_huff_ctx	ctx;

	if (argc < 2)
	{
		printf("Usage: %s <string to encode>\n", argv[0]);
		return (1);
	}
	ctx.input = argv[1];
	count_frequencies(&ctx);
	process_huffman(&ctx);
	return (0);
}

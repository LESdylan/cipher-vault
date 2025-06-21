/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huff_freq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:35:00 by dlesieur          #+#    #+#             */
/*   Updated: 2025/06/21 19:35:00 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huff.h"

void	initialize_freq_array(int *freq)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		freq[i] = 0;
		i++;
	}
}

void	calculate_char_freq(char *s, int *freq)
{
	int	unique;
	int	i;

	unique = 0;
	i = 0;
	while (s[i])
	{
		if (freq[(unsigned char)s[i]] == 0)
			unique++;
		freq[(unsigned char)s[i]]++;
		i++;
	}
}

void	build_char_arrays(int *freq, char *chars, int *f, int *n)
{
	int	i;

	*n = 0;
	i = 0;
	while (i < 256)
	{
		if (freq[i])
		{
			chars[*n] = (char)i;
			f[*n] = freq[i];
			(*n)++;
		}
		i++;
	}
}

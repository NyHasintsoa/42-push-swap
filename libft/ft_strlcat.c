/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:04 by nramalan          #+#    #+#             */
/*   Updated: 2026/01/26 12:45:43 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_sum;
	size_t	length_src;
	size_t	j;
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	j = ft_strlen(dst);
	length_src = ft_strlen(src);
	length_sum = length_src + size;
	if (size > j)
		length_sum = j + length_src;
	while (src[i] && size > ((i + j) + 1))
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (length_sum);
}

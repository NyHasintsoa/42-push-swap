/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:14:07 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/27 21:13:42 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	size_t	length;
	size_t	i;
	size_t	j;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[length] = '\0';
	return (str);
}

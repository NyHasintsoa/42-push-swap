/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:42 by nramalan          #+#    #+#             */
/*   Updated: 2026/01/29 09:03:46 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;
	char	*str;
	size_t	i;
	char	target;

	str = (char *)s;
	length = ft_strlen(s);
	target = (char) c;
	if (!s)
		return (NULL);
	i = 0;
	while (i <= length)
	{
		if (str[length - i] == target)
			return ((char *) &str[length - i]);
		i++;
	}
	return (NULL);
}

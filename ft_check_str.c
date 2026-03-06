/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:00:02 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/27 13:38:11 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"
#include "libft.h"

static int	ft_words_are_numeric(char *words[])
{
	int	i;

	i = 0;
	while (words[i])
	{
		if (!ft_strisnumeric(words[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**ft_free_all(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static int	ft_words_length(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		i++;
	return (i);
}

static void	ft_check_words(char **words, int len)
{
	if (!ft_words_are_numeric(words)
		|| !ft_words_is_in_range(words))
	{
		ft_free_all(words, len - 1);
		ft_error();
	}
}

int	*ft_check_str(char *argv)
{
	unsigned int	i;
	char			**words;
	int				*tab;
	int				length;

	words = ft_split(argv, ' ');
	if (!words)
		return (NULL);
	length = ft_words_length(words);
	ft_check_words(words, length);
	tab = (int *) malloc(sizeof(int) * (length + 1));
	if (!tab)
	{
		ft_free_all(words, length - 1);
		return (NULL);
	}
	i = 0;
	while (words[i])
	{
		tab[i] = (int) ft_atol(words[i]);
		i++;
	}
	tab[i] = 0;
	ft_free_all(words, length - 1);
	return (tab);
}

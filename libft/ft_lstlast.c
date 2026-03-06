/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:57:08 by nramalan          #+#    #+#             */
/*   Updated: 2026/01/26 11:05:52 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	length;
	int	i;

	length = ft_lstsize(lst);
	i = 0;
	if (!lst)
		return (NULL);
	while (i < (length - 1))
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

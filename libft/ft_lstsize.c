/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:36:44 by lmorgana          #+#    #+#             */
/*   Updated: 2021/04/23 20:36:45 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (lst)
	{
		count = 1;
		while (lst->next != NULL)
		{
			count++;
			lst = lst->next;
		}
		return (count);
	}
	return (0);
}

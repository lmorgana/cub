/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:32:21 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:32:23 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_splst	*ft_create_splst(int i, int j)
{
	t_splst	*splst;

	splst = malloc(sizeof(t_splst));
	if (splst)
	{
		splst->i = i;
		splst->j = j;
		splst->next = NULL;
		return (splst);
	}
	return (NULL);
}

void	ft_add_front(t_splst *new, t_splst **lst)
{
	new->next = (*lst);
	*lst = new;
}

void	ft_del_first(t_splst **lst)
{
	t_splst	*buff;

	if (*lst)
	{
		buff = (*lst);
		*lst = (*lst)->next;
		free(buff);
	}
}

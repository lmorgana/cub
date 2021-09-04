/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:59:16 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/24 19:59:18 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_free_texture(t_texture *texture)
{
	if (texture->we)
		free(texture->we);
	if (texture->ea)
		free(texture->ea);
	if (texture->no)
		free(texture->no);
	if (texture->so)
		free(texture->so);
	if (texture->c)
		free(texture->c);
	if (texture->f)
		free(texture->f);
	return (1);
}

int	ft_len_space(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

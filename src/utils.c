/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:03:34 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/08 17:21:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

unsigned	long	ft_get_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	ft_clear_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_is_equal(char *str1, char *str2)
{
	if (str1 && str2)
	{
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0 \
		&& ft_strlen(str1) == ft_strlen(str2))
			return (1);
	}
	return (0);
}

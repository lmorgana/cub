/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:03:34 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/24 20:03:36 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_clear_arr(char **arr)
{
	int	i;

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
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0
		&& ft_strlen(str1) == ft_strlen(str2))
			return (1);
	}
	return (0);
}

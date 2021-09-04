/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:45:47 by lmorgana          #+#    #+#             */
/*   Updated: 2021/04/20 20:45:48 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		z;
	size_t	len_s1;
	char	*s2;

	len_s1 = ft_strlen(s1) + 1;
	s2 = malloc(len_s1);
	if (s2)
	{
		z = ft_strlcpy(s2, s1, len_s1);
		return (s2);
	}
	return (NULL);
}

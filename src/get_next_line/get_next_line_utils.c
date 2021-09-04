/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:59:06 by lmorgana          #+#    #+#             */
/*   Updated: 2021/04/27 17:59:07 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	if (dst && src)
	{
		if (dstsize > 0)
		{
			i = 0;
			while (i < dstsize - 1 && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (ft_strlen(src));
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*str;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
		if (str)
		{
			i = ft_strlcpy(str, s1, len_s1 + 1);
			i = ft_strlcpy(&str[i], s2, len_s2 + 1);
			return (str);
		}
	}
	return (NULL);
}

int	ft_get_lens(int len_s, int start, int len)
{
	len_s = len_s - start;
	if (len_s > (int) len)
		len_s = (int) len;
	if (len_s <= 0)
		len_s = 1;
	else
		len_s++;
	return (len_s);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*substr;

	if (!s)
		return (NULL);
	substr = malloc((ft_get_lens(ft_strlen(s), start, len)) * sizeof(char));
	if (substr)
	{
		i = 0;
		while (i < len && start < ft_strlen(s) && s[start + i] != '\0')
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}

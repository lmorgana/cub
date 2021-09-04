/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:08:21 by lmorgana          #+#    #+#             */
/*   Updated: 2021/04/26 22:08:23 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_add_rem(char *rem, char *buff)
{
	char	*l_rem;

	if (!rem)
		return (ft_substr(buff, 0, ft_strlen(buff)));
	else
	{
		l_rem = rem;
		rem = ft_strjoin(rem, buff);
		free(l_rem);
		l_rem = NULL;
		return (rem);
	}
}

int	ft_del_all(char **rem, char *buff, int st)
{
	if (st == 1)
	{
		if (rem)
			free(*rem);
		if (buff)
			free(buff);
		return (-1);
	}
	else if (st == 2)
	{
		if (*rem)
		{
			free(*rem);
			*rem = NULL;
		}
		return (0);
	}
	return (-1);
}

int	ft_check_buff(char *buff)
{
	int	i;
	int	len_buff;

	if (!buff)
		return (0);
	i = 0;
	len_buff = ft_strlen(buff);
	while (i < len_buff)
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_mk_ln(char **rem)
{
	char	*ptr;
	char	*l_rem;
	int		i;

	l_rem = *rem;
	i = 0;
	while (l_rem[i] != '\0')
	{
		if (l_rem[i] == '\n')
			break ;
		i++;
	}
	ptr = ft_substr(*rem, 0, i);
	*rem = ft_substr(l_rem, i + 1, ft_strlen(*rem));
	free(l_rem);
	l_rem = NULL;
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	static char	*rem;
	char		*buff;
	int			str;

	if (fd < 0 || !line || !BUFFER_SIZE || BUFFER_SIZE < 1)
		return (-1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	str = 1;
	while (str && !ft_check_buff(rem))
	{
		str = read(fd, buff, BUFFER_SIZE);
		if (str < 0)
			return (ft_del_all(&rem, buff, 1));
		buff[str] = '\0';
		rem = ft_add_rem(rem, buff);
	}
	*line = ft_mk_ln(&rem);
	free(buff);
	if (str == 0)
		return (ft_del_all(&rem, buff, 2));
	return (1);
}

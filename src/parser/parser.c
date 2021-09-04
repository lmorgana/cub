/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:59:09 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/24 19:59:11 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	char	*ft_ch_nm_file(char *name)
{
	char	*str;

	if (name)
	{
		str = ft_strnstr(name, ".ber", ft_strlen(name));
		if (str && ft_strlen(str) == 4)
		{
			return (name);
		}
	}
	return (NULL);
}

static	void	ft_lstclr(t_list *lst)
{
	t_list	*bf;

	while (lst)
	{
		bf = lst;
		lst = lst->next;
		free(bf);
	}
}

static	char	**ft_get_arr(t_list *lst)
{
	int		i;
	char	**arr;

	i = 0;
	lst = lst->next;
	if (lst)
	{
		arr = malloc (sizeof(char *) * ft_lstsize(lst) + 1);
		if (!arr)
			return (NULL);
		while (lst)
		{
			arr[i] = lst->content;
			lst = lst->next;
			i++;
		}
		arr[i] = NULL;
		return (arr);
	}
	return (NULL);
}

static	char	**get_arr_from_file(char *path)
{
	int		fd;
	char	*buff;
	char	**arr;
	t_list	*lst;
	int		x;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = ft_lstnew(NULL);
	x = get_next_line(fd, &buff);
	while (x > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(buff));
		x = get_next_line(fd, &buff);
	}
	if (x < 0)
	{
		ft_lstclear(&lst, free);
		return (NULL);
	}
	ft_lstadd_back(&lst, ft_lstnew(buff));
	arr = ft_get_arr(lst);
	ft_lstclr(lst);
	return (arr);
}

char	**parser(t_vars *vars, char *path)
{
	char	**arr;
	char	**data;
	char	**map;

	(void) vars;
	arr = get_arr_from_file(ft_ch_nm_file(path));
	if (arr == NULL )
	{
		ft_clear_arr(arr);
		return (0);
	}
	data = get_data(arr);
	map = get_map(arr);
	if (ft_check_map(map, vars) == 0 || ft_check_data(data, vars) == 0)
	{
		ft_clear_arr(data);
		ft_clear_arr(map);
		ft_clear_arr(arr);
		return (0);
	}
	ft_clear_arr(data);
	ft_clear_arr(arr);
	return (map);
}

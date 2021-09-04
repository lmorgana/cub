/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:36:36 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:36:38 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	void	ft_init_data(t_vars *vars)
{
	vars->texture.we = NULL;
	vars->texture.ea = NULL;
	vars->texture.so = NULL;
	vars->texture.no = NULL;
	vars->texture.f = NULL;
	vars->texture.c = NULL;
}

int	ft_is_texture_we(char **name_value, t_vars *vars)
{
	if (ft_is_equal(name_value[0], "WE"))
	{
		if (vars->texture.we != NULL)
		{
			free(name_value[0]);
			if (name_value[1])
				free(name_value[1]);
			free(name_value);
			return (-1);
		}
		else
		{
			vars->texture.we = name_value[1];
			free(name_value[0]);
			free(name_value);
			return (1);
		}
	}
	return (0);
}

static	int	ft_check(char **name_value, t_vars *vars)
{
	if (ft_is_texture_we(name_value, vars) == -1)
		return (0);
	else if (ft_is_texture_ea(name_value, vars) == -1)
		return (0);
	else if (ft_is_texture_no(name_value, vars) == -1)
		return (0);
	else if (ft_is_texture_so(name_value, vars) == -1)
		return (0);
	else if (ft_is_texture_f(name_value, vars) == -1)
		return (0);
	else if (ft_is_texture_c(name_value, vars) == -1)
		return (0);
	return (1);
}

int	ft_check_full(t_vars *vars)
{
	if (vars->texture.we == NULL)
		return (0);
	if (vars->texture.ea == NULL)
		return (0);
	if (vars->texture.no == NULL)
		return (0);
	if (vars->texture.so == NULL)
		return (0);
	if (vars->texture.c == NULL)
		return (0);
	if (vars->texture.f == NULL)
		return (0);
	return (1);
}

int	ft_check_data(char **data, t_vars *vars)
{
	int		i;
	char	**name_value;

	ft_init_data(vars);
	i = 0;
	if (!data)
		return (0);
	while (data[i])
	{
		name_value = ft_split(data[i], ' ');
		if (ft_check(name_value, vars) == 0)
			return (0);
		i++;
	}
	if (ft_check_full(vars) == 0)
	{
		ft_free_texture(&vars->texture);
		return (0);
	}
	return (1);
}

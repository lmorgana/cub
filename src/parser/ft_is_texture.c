/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:36:58 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:37:01 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_is_texture_ea(char **name_value, t_vars *vars)
{
	if (ft_is_equal(name_value[0], "EA"))
	{
		if (vars->texture.ea != NULL)
		{
			free(name_value[0]);
			if (name_value[1])
				free(name_value[1]);
			free(name_value);
			return (-1);
		}
		else
		{
			vars->texture.ea = name_value[1];
			free(name_value[0]);
			free(name_value);
			return (1);
		}
	}
	return (0);
}

int	ft_is_texture_no(char **name_value, t_vars *vars)
{
	if (ft_is_equal(name_value[0], "NO"))
	{
		if (vars->texture.no != NULL)
		{
			free(name_value[0]);
			if (name_value[1])
				free(name_value[1]);
			free(name_value);
			return (-1);
		}
		else
		{
			vars->texture.no = name_value[1];
			free(name_value[0]);
			free(name_value);
			return (1);
		}
	}
	return (0);
}

int	ft_is_texture_so(char **name_value, t_vars *vars)
{
	if (ft_is_equal(name_value[0], "SO"))
	{
		if (vars->texture.so != NULL)
		{
			free(name_value[0]);
			if (name_value[1])
				free(name_value[1]);
			free(name_value);
			return (-1);
		}
		else
		{
			vars->texture.so = name_value[1];
			free(name_value[0]);
			free(name_value);
			return (1);
		}
	}
	return (0);
}

int	ft_is_texture_f(char **name_value, t_vars *vars)
{
	if (ft_is_equal(name_value[0], "F"))
	{
		if (vars->texture.f != NULL)
		{
			free(name_value[0]);
			if (name_value[1])
				free(name_value[1]);
			free(name_value);
			return (-1);
		}
		else
		{
			vars->texture.f = name_value[1];
			free(name_value[0]);
			free(name_value);
			return (1);
		}
	}
	return (0);
}

int	ft_is_texture_c(char **name_value, t_vars *vars)
{
	if (ft_is_equal(name_value[0], "C"))
	{
		if (vars->texture.c != NULL)
		{
			free(name_value[0]);
			if (name_value[1])
				free(name_value[1]);
			free(name_value);
			return (-1);
		}
		else
		{
			vars->texture.c = name_value[1];
			free(name_value[0]);
			free(name_value);
			return (1);
		}
	}
	return (0);
}

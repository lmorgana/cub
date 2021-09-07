/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:51:24 by lmorgana          #+#    #+#             */
/*   Updated: 2021/09/05 18:51:26 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	int	ft_len(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	ft_get_color(char *str, unsigned long *color)
{
	char	**digits;
	int		r;
	int		g;
	int		b;

	digits = ft_split(str, ',');
	if (digits && ft_len(digits) == 3)
	{
		r = ft_atoi(digits[0]);
		g = ft_atoi(digits[1]);
		b = ft_atoi(digits[2]);
		if (r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0)
		{
			*color = ft_get_rgb(r, g, b);
			ft_clear_arr(digits);
			return (1);
		}
		ft_clear_arr(digits);
	}
	return (0);
}

static	int	ft_is_color(char *str)
{
	int	i;
	int	len_numb;

	i = 0;
	len_numb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			if (len_numb > 3)
				return (0);
			len_numb = 0;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		else
			len_numb++;
		i++;
	}
	return (1);
}

static	int	ft_valid_fc(t_vars *vars)
{
	if (ft_is_color(vars->texture.c) && ft_is_color(vars->texture.f))
	{
		if (ft_get_color(vars->texture.c, &vars->color_c) && \
		ft_get_color(vars->texture.f, &vars->color_f))
			return (1);
	}
	return (0);
}

int	ft_valid_data(t_vars *vars)
{
	if (ft_valid_fc(vars) == 0)
		return (0);
	if (ft_valid_texture(vars) == 0)
		return (0);
	return (1);
}

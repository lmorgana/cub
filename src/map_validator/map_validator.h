/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:32:28 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/27 12:32:30 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

typedef struct s_splst
{
	int				i;
	int				j;
	struct s_splst	*next;
}				t_splst;

typedef struct s_hero
{
	int		i;
	int		j;
	char	ch;
}				t_hero;

t_splst	*ft_create_splst(int i, int j);
void	ft_add_front(t_splst *new, t_splst **lst);
void	ft_del_first(t_splst **lst);
int		ft_is_surround(char **map);

#endif

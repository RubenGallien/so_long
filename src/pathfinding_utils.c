/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:00:04 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/18 18:13:20 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_left(char **map, int x, int y)
{
	while (map[y][x] != '1')
	{
		map[y][x] = 'x';
		x--;
	}
}

void	fill_right(char **map, int x, int y)
{
	while (map[y][x] != '1')
	{
		map[y][x] = 'x';
		x++;
	}
}

void	fill_up(char **map, int x, int y)
{
	while (map[y][x] != '1')
	{
		map[y][x] = 'x';
		y--;
	}
}

void	fill_down(char **map, int x, int y)
{
	while (map[y][x] != '1')
	{
		map[y][x] = 'x';
		y++;
	}
}

void	find_p(char **map, t_pos *pos)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j] && map[j][i] != 'P')
	{
		i = 0;
		while (map[j][i] && map[j][i] != 'P')
			i++;
		if (map[j][i] == 'P')
			break ;
		else
			j++;
	}
	pos->x = i;
	pos->y = j;
}

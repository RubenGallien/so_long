/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:13:37 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/15 12:02:09 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_style(t_data *data, t_img *img, int i, int j)
{
	int	x;
	int	y;
	int	random;

	y = 37;
	i = 0;
	srand(time(NULL));
	while (data->map[++i])
	{
		x = 7;
		j = -1;
		while (data->map[i][++j])
		{
			random = rand() % 50;
			if (data->map[i][j] == '0' && random <= 2)
				draw_sprite(data->asset.g_style[random], img, x, y);
			if (data->map[i][j] == '1' && random <= 2)
				draw_sprite(data->asset.w_style[random], img, x, y);
			x = x + 32;
		}
		y = y + 32;
	}
}

void	fill_exit(t_data *data, t_img *img)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = -24;
	while (data->map[i])
	{
		x = -8;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				draw_sprite(data->asset.house, img, x, y);
			x = x + 32;
			j++;
		}
		i++;
		y = y + 32;
	}
}

void	fill_player(t_data *data, t_img *img, t_player *player)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 2;
	while (data->map[++i])
	{
		x = 9;
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				draw_sprite(data->asset.char_down, img, x, y);
				player->index[0] = i + (0.125 * 3);
				player->index[1] = j + (0.125 * 3);
				player->x = x;
				player->y = y;
			}
			x = x + 32;
		}
		y = y + 32;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:44:39 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 14:46:44 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ending(t_data *data, int keysim)
{
	if (keysim == UP && data->map[(int)(data->player.index[0] - 0.123) \
	][(int)(data->player.index[1])] == 'E')
		data->player.finish = 1;
	else if (keysim == DOWN && data->map[(int)(data->player.index[0] + 0.124) \
	][(int)(data->player.index[1])] == 'E')
		data->player.finish = 1;
	else if (keysim == LEFT && data->map[(int)(data->player.index[0]) \
	][(int)(data->player.index[1] - (0.124))] == 'E')
		data->player.finish = 1;
	else if (keysim == RIGHT && data->map[(int)(data->player.index[0]) \
	][(int)(data->player.index[1] + (0.124))] == 'E')
		data->player.finish = 1;
	else
		data->player.finish = 0;
}

long int	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	last_position(t_data *data, int keysim)
{
	if (keysim == UP)
	{
		data->player.keysim = UP;
		data->player.lastpos = data->asset.char_up;
	}
	else if (keysim == DOWN)
	{
		data->player.keysim = DOWN;
		data->player.lastpos = data->asset.char_down;
	}
	else if (keysim == RIGHT)
	{
		data->player.keysim = RIGHT;
		data->player.lastpos = data->asset.char_right;
	}
	else if (keysim == LEFT)
	{
		data->player.keysim = LEFT;
		data->player.lastpos = data->asset.char_left;
	}
}

void	draw_step_aux(t_data *data, t_img *img, char *step, int *tab)
{
	if (step[tab[0]] == '0')
		draw_sprite(data->asset.zero, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '1')
		draw_sprite(data->asset.one, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '2')
		draw_sprite(data->asset.two, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '3')
		draw_sprite(data->asset.three, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '4')
		draw_sprite(data->asset.four, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '5')
		draw_sprite(data->asset.five, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '6')
		draw_sprite(data->asset.six, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '7')
		draw_sprite(data->asset.seven, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '8')
		draw_sprite(data->asset.eight, img, tab[1], data->tab[1] - 20);
	else if (step[tab[0]] == '9')
		draw_sprite(data->asset.nine, img, tab[1], data->tab[1] - 20);
}

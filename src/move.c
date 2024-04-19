/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:34:24 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 14:47:59 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_index(t_data *data, int keysim)
{
	if (keysim == RIGHT)
		data->player.index[1] += 0.125;
	if (keysim == LEFT)
		data->player.index[1] -= 0.125;
	if (keysim == DOWN)
		data->player.index[0] += 0.125;
	if (keysim == UP)
		data->player.index[0] -= 0.125;
}

int	check_eggs(t_data *data, int keysim)
{
	if (keysim == UP && data->map[(int)(data->player.index[0] - 0.123) \
	][(int)(data->player.index[1])] == 'C')
		data->map[(int)(data->player.index[0] - 0.125) \
		][(int)(data->player.index[1])] = '0';
	else if (keysim == DOWN && data->map[(int)(data->player.index[0] + 0.124) \
	][(int)(data->player.index[1])] == 'C')
		data->map[(int)(data->player.index[0] + 0.125)] \
		[(int)(data->player.index[1])] = '0';
	else if (keysim == LEFT && data->map[(int)(data->player.index[0]) \
	][(int)(data->player.index[1] - (0.124))] == 'C')
		data->map[(int)(data->player.index[0])] \
		[(int)(data->player.index[1] - (0.125))] = '0';
	else if (keysim == RIGHT && data->map[(int)(data->player.index[0]) \
	][(int)(data->player.index[1] + (0.124))] == 'C')
		data->map[(int)(data->player.index[0])] \
		[(int)(data->player.index[1] + (0.125))] = '0';
	else
		return (1);
	return (0);
}

void	draw_step(t_data *data, t_img *img, char *step)
{
	int	tab[2];

	tab[0] = -1;
	tab[1] = 5;
	while (++tab[0] < (int)ft_strlen(step))
	{
		draw_step_aux(data, img, step, tab);
		tab[1] += 20;
	}
	free(step);
}

int	set_player(t_data *data, int keysim)
{
	time(&data->time);
	last_position(data, keysim);
	if (keysim == UP && data->map[(int)(data->player.index[0] - 0.2) \
	][(int)(data->player.index[1])] != '1')
		data->player.y -= 4;
	else if (keysim == DOWN && data->map[(int)(data->player.index[0] + 0.5) \
	][(int)(data->player.index[1])] != '1')
		data->player.y += 4;
	else if (keysim == LEFT && data->map[(int)(data->player.index[0]) \
	][(int)(data->player.index[1] - (0.125 * 4))] != '1')
		data->player.x -= 4;
	else if (keysim == RIGHT && data->map[(int)(data->player.index[0]) \
	][(int)(data->player.index[1] + (0.125 * 4))] != '1')
		data->player.x += 4;
	else
		return (1);
	update_index(data, keysim);
	ending(data, keysim);
	return (0);
}

int	ft_move_player(int keysim, t_data *data)
{
	draw_sprite(data->img, &data->img_dup, 0, 0);
	if (!check_eggs(data, keysim))
		data->player.c++;
	if (!set_player(data, keysim))
		data->player.step += 1;
	if (keysim == UP)
		draw_sprite(data->asset.char_up_tab[(int)(data->player.index[0] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	else if (keysim == RIGHT)
		draw_sprite(data->asset.char_right_tab[(int)(data->player.index[1] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	else if (keysim == DOWN)
		draw_sprite(data->asset.char_down_tab[(int)(data->player.index[0] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	else if (keysim == LEFT)
		draw_sprite(data->asset.char_left_tab[(int)(data->player.index[1] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	fill_collectibles(data, &data->img_dup);
	fill_exit(data, &data->img_dup);
	draw_step(data, &data->img_dup, ft_itoa(data->player.step));
	if (data->player.c >= 1)
		draw_sprite(data->asset.chicken, &data->img_dup, data->monster.x, \
		data->monster.y);
	return (mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img_dup.img, 0, 0), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:16 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 15:25:19 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_update(t_data *data)
{
	if (data->time == 0)
		draw_sprite(data->player.lastpos, &data->img_dup, data->player.x, \
		data->player.y);
	else if (data->player.keysim == UP)
		draw_sprite(data->asset.char_up_tab[(int)(data->player.index[0] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	else if (data->player.keysim == DOWN)
		draw_sprite(data->asset.char_down_tab[(int)(data->player.index[0] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	else if (data->player.keysim == RIGHT)
		draw_sprite(data->asset.char_right_tab[(int)(data->player.index[1] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
	else if (data->player.keysim == LEFT)
		draw_sprite(data->asset.char_left_tab[(int)(data->player.index[1] \
		* 1000) % 250 % 124], &data->img_dup, data->player.x, data->player.y);
}

void	find_and_put_monster(t_data *data)
{
	float	diff_y;
	float	diff_x;

	diff_y = data->player.index[0] - data->monster.pos[0];
	diff_x = data->player.index[1] - data->monster.pos[1];
	if (diff_y < 0)
	{
		data->monster.pos[0] -= 0.03125;
		data->monster.y -= 1;
	}
	else if (diff_y > 0)
	{
		data->monster.pos[0] += 0.03125;
		data->monster.y += 1;
	}
	if (diff_x < 0)
	{
		data->monster.pos[1] -= 0.03125;
		data->monster.x -= 1;
	}
	else if (diff_x > 0)
	{
		data->monster.pos[1] += 0.03125;
		data->monster.x += 1;
	}
}

void	monster(t_data *data)
{
	draw_sprite(data->img, &data->img_dup, 0, 0);
	draw_player_update(data);
	fill_collectibles(data, &data->img_dup);
	fill_exit(data, &data->img_dup);
	draw_step(data, &data->img_dup, ft_itoa(data->player.step));
	draw_sprite(data->asset.chicken, &data->img_dup, data->monster.x, \
	data->monster.y);
	find_and_put_monster(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img_dup.img, 0, 0);
	data->monster.chrono = get_current_time();
	data->monster.active = 1;
}

void	update_last_position(t_data *data)
{
	draw_sprite(data->img, &data->img_dup, 0, 0);
	draw_sprite(data->player.lastpos, &data->img_dup, data->player.x, \
	data->player.y);
	fill_collectibles(data, &data->img_dup);
	fill_exit(data, &data->img_dup);
	draw_step(data, &data->img_dup, ft_itoa(data->player.step));
	if (data->player.c >= 1)
		draw_sprite(data->asset.chicken, &data->img_dup, data->monster.x, \
		data->monster.y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img_dup.img, 0, 0);
	data->time = 0;
}

int	animation(t_data *data)
{
	time_t	checker;

	time(&checker);
	if (data->time != 0 && difftime(checker, data->time) >= 0.5)
		update_last_position(data);
	if (data->player.c >= 1 && data->monster.active == 0)
		monster(data);
	if (data->monster.active == 1)
		check_active(data);
	if (fabs(data->monster.pos[0] - data->player.index[0]) < (0.226) && \
	fabs(data->monster.pos[1] - data->player.index[1]) < (0.226))
	{
		ft_printf("You loose\no o\n O\n");
		on_destroy(data);
		exit(EXIT_SUCCESS);
	}
	if (data->player.finish == 1 && data->player.c == data->player.c_max)
	{
		ft_printf("You win\no o\n O\n");
		on_destroy(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

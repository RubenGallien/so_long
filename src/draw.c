/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:29:47 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 14:05:59 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_collectibles(t_data *data, t_img *img)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 5;
	while (data->map[i])
	{
		x = 8;
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C')
				draw_sprite(data->asset.egg, img, x, y);
			x = x + 32;
		}
		i++;
		y = y + 32;
	}
}

void	fill_background(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	j;
	int	i;

	y = 0;
	i = 0;
	while (data->map[i])
	{
		x = 0;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_sprite(data->asset.water, img, x, y);
			x = x + 32;
			j++;
		}
		i++;
		y = y + 32;
	}
}

void	fill_land(t_data *data, t_img *img)
{
	int	j;
	int	i;

	data->y = 0;
	j = 0;
	while (data->map[j])
	{
		data->x = 0;
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != '1')
				ft_sense(data, i, j, img);
			i++;
			data->x = data->x + 32;
		}
		j++;
		data->y = data->y + 32;
	}
}

int	display(t_data *data, t_img *img, t_img *img_dup, t_player *player)
{
	fill_background(data, img);
	fill_land(data, img);
	fill_style(data, img, -1, -1);
	img_dup->width = img->width;
	img_dup->height = img->height;
	img_dup->img = mlx_new_image(data->mlx_ptr, img->width, img->height);
	img_dup->pixels = (unsigned char *)mlx_get_data_addr(data->img_dup.img, \
	&data->img_dup.bits_per_pixel, &data->img_dup.line_length, \
	&data->img_dup.endian);
	img_dup->pixels = ft_memcpy(img_dup->pixels, img->pixels, \
	img->line_length * img->height);
	fill_collectibles(data, img_dup);
	fill_exit(data, img_dup);
	fill_player(data, img_dup, player);
	return (0);
}

void	main_display(t_data *data, int width, int height)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, \
	"so_long");
	data->img.height = height;
	data->img.width = width;
	data->img.img = mlx_new_image(data->mlx_ptr, width, height);
	data->img.pixels = (unsigned char *)mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	display(data, &data->img, &data->img_dup, &data->player);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, \
	&on_destroy, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img_dup.img, 0, 0);
	mlx_loop_hook(data->mlx_ptr, animation, data);
	mlx_loop(data->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:02:58 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 15:09:58 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_active(t_data *data)
{
	long int	current_time;

	current_time = get_current_time();
	if (current_time - data->monster.chrono >= 40)
		data->monster.active = 0;
}

void	init_monster(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	i = -1;
	while (data->map[++i])
	{
		x = 0;
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'E')
			{
				data->monster.x = x;
				data->monster.y = y;
				data->monster.pos[0] = i + (2 * 0.125);
				data->monster.pos[1] = j + (1 * 0.125);
				return ;
			}
			x += 32;
		}
		y += 32;
	}
}

int	draw_sprite(t_img asset, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned char	*dst;
	unsigned int	color;

	i = 0;
	while (i < asset.width)
	{
		j = -1;
		while (++j < asset.height)
		{
			color = ((int *)asset.pixels)[j * asset.width + i];
			if (color == 0xFF000000)
				continue ;
			dst = img->pixels + ((y + j) * img->line_length + (x + i) \
			* (img->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
		i++;
	}
	return (1);
}

int	set_data_assets(t_data *data, char *_path, t_img *asset)
{
	asset->img = mlx_xpm_file_to_image(data->mlx_ptr, _path, &asset->width, \
	&asset->height);
	asset->pixels = (unsigned char *)mlx_get_data_addr(asset->img, \
	&asset->bits_per_pixel, &asset->line_length, &asset->endian);
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

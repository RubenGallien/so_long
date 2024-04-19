/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:32:26 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/25 16:48:16 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_3_1_other(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i - 1] == '1' && data->map[j - 1][i] == '1')
	{
		if (data->map[j + 1][i + 1] == '1')
			draw_sprite(data->asset.land_9_1, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_7_1, img, data->x, data->y);
	}
	else if (data->map[j][i + 1] == '1')
	{
		if (data->map[j + 1][i - 1] == '1' && data->map[j - 1][i - 1])
			draw_sprite(data->asset.land_8_5, img, data->x, data->y);
		else if (data->map[j + 1][i - 1] == '1')
			draw_sprite(data->asset.land_8_2, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_8_3, img, data->x, data->y);
	}
	else if (data->map[j + 1][i] == '1' && data->map[j - 1][i + 1] == '1')
		ft_3_1_2_2_except(data, i, j, img);
}

void	ft_3_1_4_0(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j - 1][i] == '1')
		draw_sprite(data->asset.t_m_land, img, data->x, data->y);
	else if (data->map[j][i - 1] == '1')
		draw_sprite(data->asset.m_l_land, img, data->x, data->y);
	else if (data->map[j][i + 1] == '1')
		draw_sprite(data->asset.m_r_land, img, data->x, data->y);
	else
		draw_sprite(data->asset.d_m_land, img, data->x, data->y);
}

void	ft_2_2_1_3_aux(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i] != '1' && data->map[j][i + 1] == '1')
	{
		if (data->map[j][i - 1] == '1')
			draw_sprite(data->asset.mid_land2, img, data->x, data->y);
		else
			draw_sprite(data->asset.t_r_land, img, data->x, data->y);
	}
	else
	{
		if (data->map[j][i + 1] != '1' && data->map[j - 1][i + 1] != '1')
			draw_sprite(data->asset.d_l_land, img, data->x, data->y);
		else if (data->map[j][i - 1] != '1' && data->map[j - 1][i - 1] != '1')
			draw_sprite(data->asset.d_r_land, img, data->x, data->y);
		else if (data->map[j][i - 1] != '1')
			draw_sprite(data->asset.land_8_4, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_5_4, img, data->x, data->y);
	}
}

void	ft_2_2_aux(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j - 1][i] != '1')
		draw_sprite(data->asset.mid_land2, img, data->x, data->y);
	else if (data->map[j][i - 1] == '1' && data->map[j + 1][i + 1] == '1')
		draw_sprite(data->asset.land_5_1, img, data->x, data->y);
	else if (data->map[j][i - 1] == '1')
		draw_sprite(data->asset.t_l_land, img, data->x, data->y);
	else if (data->map[j + 1][i - 1] == '1')
		draw_sprite(data->asset.land_8_1, img, data->x, data->y);
	else
		draw_sprite(data->asset.t_r_land, img, data->x, data->y);
}

void	put_for_3_1_aux(t_data *data, int i, int j, t_img *img)
{
	if (data->design[2] == 4 && data->design[3] == 0)
		ft_3_1_4_0(data, i, j, img);
	else if (data->design[2] == 3 && data->design[3] == 1)
		ft_3_1_3_1_aux(data, i, j, img);
}

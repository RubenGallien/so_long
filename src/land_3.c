/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:29 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/25 16:34:58 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_1_3_0_4(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j - 1][i] != '1')
		draw_sprite(data->asset.d_m_land2, img, data->x, data->y);
	else if (data->map[j][i + 1] != '1')
		draw_sprite(data->asset.m_l_land2, img, data->x, data->y);
	else if (data->map[j][i - 1] != '1')
		draw_sprite(data->asset.m_r_land2, img, data->x, data->y);
	else if (data->map[j + 1][i] != '1')
		draw_sprite(data->asset.t_m_land2, img, data->x, data->y);
}

void	ft_4_0_1_3(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i + 1] != '1')
		draw_sprite(data->asset.land_10_3, img, data->x, data->y);
	else if (data->map[j + 1][i - 1] != '1')
		draw_sprite(data->asset.land_11_3, img, data->x, data->y);
	else if (data->map[j - 1][i + 1] != '1')
		draw_sprite(data->asset.land_10_4, img, data->x, data->y);
	else if (data->map[j - 1][i - 1] != '1')
		draw_sprite(data->asset.land_11_4, img, data->x, data->y);
}

void	ft_4_0_2_2(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j - 1][i + 1] == '1')
	{
		if (data->map[j + 1][i - 1] == '1')
			draw_sprite(data->asset.land_10_1, img, data->x, data->y);
		else if (data->map[j - 1][i - 1] == '1')
			draw_sprite(data->asset.land_9_3, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_6_5, img, data->x, data->y);
	}
	else if (data->map[j + 1][i + 1] == '1')
	{
		if (data->map[j - 1][i - 1] == '1')
			draw_sprite(data->asset.land_10_2, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_9_2, img, data->x, data->y);
	}
	else
		draw_sprite(data->asset.land_8_5, img, data->x, data->y);
}

void	ft_4_0_3_1(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i + 1] == '1')
		draw_sprite(data->asset.land_6_2, img, data->x, data->y);
	else if (data->map[j + 1][i - 1] == '1')
		draw_sprite(data->asset.land_7_2, img, data->x, data->y);
	else if (data->map[j - 1][i + 1] == '1')
		draw_sprite(data->asset.land_6_3, img, data->x, data->y);
	else if (data->map[j - 1][i - 1] == '1')
		draw_sprite(data->asset.land_7_3, img, data->x, data->y);
}

void	ft_3_1_0_4(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i] == '1')
		draw_sprite(data->asset.land_9_4, img, data->x, data->y);
	else if (data->map[j - 1][i] == '1')
		draw_sprite(data->asset.land_9_1, img, data->x, data->y);
	else if (data->map[j][i - 1] == '1')
		draw_sprite(data->asset.land_5_5, img, data->x, data->y);
	else
		draw_sprite(data->asset.land_8_5, img, data->x, data->y);
}

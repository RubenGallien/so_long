/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:39:56 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/25 16:47:57 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_3_1_2_2(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i - 1] == '1' && data->map[j - 1][i] == '1')
		ft_3_1_other(data, i, j, img);
	else if (data->map[j - 1][i] == '1')
		draw_sprite(data->asset.t_m_land, img, data->x, data->y);
	else if (data->map[j + 1][i] == '1' && data->map[j - 1][i + 1] != '1')
		draw_sprite(data->asset.d_m_land, img, data->x, data->y);
	else if (data->map[j + 1][i] == '1')
		ft_3_1_other(data, i, j, img);
	else if (data->map[j][i + 1] == '1')
		ft_3_1_2_2_aux(data, i, j, img);
	else if (data->map[j + 1][i + 1] == '1' && data->map[j - 1][i + 1] == '1')
		draw_sprite(data->asset.land_5_5, img, data->x, data->y);
	else if (data->map[j + 1][i + 1] == '1')
		draw_sprite(data->asset.land_5_2, img, data->x, data->y);
	else if (data->map[j - 1][i + 1] == '1')
		draw_sprite(data->asset.land_5_3, img, data->x, data->y);
	else
		draw_sprite(data->asset.m_l_land, img, data->x, data->y);
}

void	ft_3_1_1_3_aux(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i] == '1')
	{
		if (data->map[j - 1][i + 1] == '1')
			draw_sprite(data->asset.land_6_4, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_7_4, img, data->x, data->y);
	}
	else if (data->map[j + 1][i + 1] == '1' && data->map[j + 1][i - 1] == '1')
		draw_sprite(data->asset.land_9_1, img, data->x, data->y);
	else
	{
		if (data->map[j + 1][i + 1] == '1')
			draw_sprite(data->asset.land_6_1, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_7_1, img, data->x, data->y);
	}
}

void	ft_3_1_1_3(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j][i - 1] == '1')
	{
		if (data->map[j + 1][i + 1] == '1' && data->map[j - 1][i + 1] == '1')
			draw_sprite(data->asset.land_5_5, img, data->x, data->y);
		else if (data->map[j + 1][i + 1] == '1')
			draw_sprite(data->asset.land_5_2, img, data->x, data->y);
		else
			draw_sprite(data->asset.land_5_3, img, data->x, data->y);
	}
	else if (data->map[j][i + 1] == '1')
		ft_3_1_other(data, i, j, img);
	else
		ft_3_1_1_3_aux(data, i, j, img);
}

void	ft_2_2_1_3(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i] == '1' && data->map[j - 1][i] == '1')
		draw_sprite(data->asset.m_m_land2, img, data->x, data->y);
	else if (data->map[j + 1][i] != '1')
	{
		if (data->map[j][i + 1] != '1' && data->map[j + 1][i + 1] == '1')
			draw_sprite(data->asset.land_5_1, img, data->x, data->y);
		else if (data->map[j][i + 1] != '1')
			draw_sprite(data->asset.t_l_land, img, data->x, data->y);
		else
		{
			if (data->map[j + 1][i] != '1' && data->map[j][i + 1] == '1' && \
			data->map[j + 1][i - 1] == '1' && data->map[j - 1][i] == '1')
				draw_sprite(data->asset.land_8_1, img, data->x, data->y);
			else
				ft_2_2_1_3_aux(data, i, j, img);
		}
	}
	else
		ft_2_2_1_3_aux(data, i, j, img);
}

void	ft_2_2_0_4(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j - 1][i] == '1')
	{
		if (data->map[j][i + 1] != '1')
		{
			if (data->map[j + 1][i] == '1')
				draw_sprite(data->asset.m_m_land2, img, data->x, data->y);
			else
				draw_sprite(data->asset.land_5_1, img, data->x, data->y);
		}
		else
			draw_sprite(data->asset.land_8_1, img, data->x, data->y);
	}
	else if (data->map[j][i - 1] == '1' && data->map[j + 1][i] == '1')
		draw_sprite(data->asset.land_5_4, img, data->x, data->y);
	else if (data->map[j][i - 1] == '1')
		draw_sprite(data->asset.mid_land2, img, data->x, data->y);
	else
		draw_sprite(data->asset.land_8_4, img, data->x, data->y);
}

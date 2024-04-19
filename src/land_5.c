/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:48:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/25 16:43:38 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_3_1_2_2_except(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j - 1][i - 1] == '1')
		draw_sprite(data->asset.land_9_4, img, data->x, data->y);
	else
		draw_sprite(data->asset.land_6_4, img, data->x, data->y);
}

void	ft_3_1_3_1_aux(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j][i - 1] == '1')
		draw_sprite(data->asset.m_l_land, img, data->x, data->y);
	else if (data->map[j - 1][i] == '1' && data->map[j + 1][i - 1] == '1')
		draw_sprite(data->asset.land_7_1, img, data->x, data->y);
	else if (data->map[j - 1][i] == '1' && data->map[j + 1][i + 1] == '1')
		draw_sprite(data->asset.land_6_1, img, data->x, data->y);
	else if (data->map[j - 1][i] == '1')
		draw_sprite(data->asset.t_m_land, img, data->x, data->y);
	else if (data->map[j + 1][i] == '1' && data->map[j - 1][i - 1] != '1')
		draw_sprite(data->asset.d_m_land, img, data->x, data->y);
	else if (data->map[j][i + 1] == '1')
		draw_sprite(data->asset.m_r_land, img, data->x, data->y);
	else
		draw_sprite(data->asset.land_7_4, img, data->x, data->y);
}

void	ft_3_1_2_2_aux(t_data *data, int i, int j, t_img *img)
{
	if (data->map[j + 1][i - 1] == '1' && data->map[j - 1][i - 1] == '1')
		draw_sprite(data->asset.land_8_5, img, data->x, data->y);
	else if (data->map[j + 1][i - 1] == '1')
		draw_sprite(data->asset.land_8_2, img, data->x, data->y);
	else if (data->map[j - 1][i - 1] == '1' && data->map[j][i + 1] == '1')
		draw_sprite(data->asset.land_8_3, img, data->x, data->y);
	else if (data->map[j - 1][i - 1] == '1')
		draw_sprite(data->asset.land_5_3, img, data->x, data->y);
	else
		draw_sprite(data->asset.m_r_land, img, data->x, data->y);
}

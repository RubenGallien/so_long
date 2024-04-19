/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:58:35 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/25 16:48:45 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_for_1_3(t_data *data, int i, int j, t_img *img)
{
	if (data->design[2] == 0 && data->design[3] == 4)
		ft_1_3_0_4(data, i, j, img);
	else if (data->map[j + 1][i] == '1' && data->map[j][i - 1] == '1')
	{
		if (data->map[j - 1][i] == '1')
			draw_sprite(data->asset.m_l_land2, img, data->x, data->y);
		else
			draw_sprite(data->asset.d_m_land2, img, data->x, data->y);
	}
	else if (data->map[j + 1][i] == '1')
		draw_sprite(data->asset.m_r_land2, img, data->x, data->y);
	else
		draw_sprite(data->asset.t_m_land2, img, data->x, data->y);
}

void	put_for_4_0(t_data *data, int i, int j, t_img *img)
{
	if (data->design[2] == 3 && data->design[3] == 1)
		ft_4_0_3_1(data, i, j, img);
	else if (data->design[2] == 2 && data->design[3] == 2 && \
	(data->map[j - 1][i + 1] != '1' && data->map[j + 1][i + 1] != '1'))
	{
		if (data->map[j][i + 1] != '1')
			draw_sprite(data->asset.land_7_5, img, data->x, data->y);
	}
	else if (data->design[2] == 2 && data->design[3] == 2)
		ft_4_0_2_2(data, i, j, img);
	else if (data->design[2] == 1 && data->design[3] == 3)
		ft_4_0_1_3(data, i, j, img);
	else if (data->design[2] == 0 && data->design[3] == 4)
		draw_sprite(data->asset.land_9_5, img, data->x, data->y);
}

void	put_for_3_1(t_data *data, int i, int j, t_img *img)
{
	if (data->design[2] == 1 && data->design[3] == 3)
		ft_3_1_1_3(data, i, j, img);
	else if (data->design[2] == 2 && data->design[3] == 2)
	{
		if (data->map[j - 1][i] == '1' && data->map[j + 1][i + 1] == '1' && \
		data->map[j + 1][i - 1] != '1')
			draw_sprite(data->asset.land_6_1, img, data->x, data->y);
		else
			ft_3_1_2_2(data, i, j, img);
	}
	else if (data->design[2] == 0 && data->design[3] == 4)
		ft_3_1_0_4(data, i, j, img);
	else
		put_for_3_1_aux(data, i, j, img);
}

void	put_for_2_2(t_data *data, int i, int j, t_img *img)
{
	if (data->design[2] == 1 && data->design[3] == 3)
		ft_2_2_1_3(data, i, j, img);
	else if (data->design[2] == 0 && data->design[3] == 4)
		ft_2_2_0_4(data, i, j, img);
	else if (data->map[j + 1][i] != '1')
		ft_2_2_aux(data, i, j, img);
	else if (data->map[j][i + 1] != '1')
	{
		if (data->map[j][i - 1] != '1')
			draw_sprite(data->asset.m_m_land2, img, data->x, data->y);
		else
			draw_sprite(data->asset.d_l_land, img, data->x, data->y);
	}
	else
		draw_sprite(data->asset.d_r_land, img, data->x, data->y);
}

void	ft_sense(t_data *data, int i, int j, t_img *img)
{
	data->design = get_tab(data, i, j);
	if (data->design[0] == 0 && data->design[1] == 4)
		draw_sprite(data->asset.m_land2, img, data->x, data->y);
	else if (data->design[0] == 2 && data->design[1] == 2)
		put_for_2_2(data, i, j, img);
	else if (data->design[0] == 0 && data->design[1] == 4 && \
	data->design[2] == 0 && data->design[3] == 4)
		draw_sprite(data->asset.m_land2, img, data->x, data->y);
	else if (data->design[0] == 3 && data->design[1] == 1)
		put_for_3_1(data, i, j, img);
	else if (data->design[0] == 4 && data->design[1] == 0)
	{
		if (data->design[2] == 4 && data->design[3] == 0)
			draw_sprite(data->asset.m_m_land, img, data->x, data->y);
		else
			put_for_4_0(data, i, j, img);
	}
	else if (data->design[0] == 1 && data->design[1] == 3)
		put_for_1_3(data, i, j, img);
	free(data->design);
}

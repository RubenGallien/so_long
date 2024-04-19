/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:21:33 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/15 15:06:31 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_style(t_data *data)
{
	int			i;
	int			c;
	const char	*style[] = {FLOW_1, FLOW_2, FLOW_3, NEN, ROCK_1, ROCK_2};

	c = -1;
	i = -1;
	while (++i < 3)
		set_data_assets(data, (char *)style[++c], &data->asset.g_style[i]);
	i = -1;
	while (++i < 3)
		set_data_assets(data, (char *)style[++c], &data->asset.w_style[i]);
}

void	init_3(t_data *data)
{
	set_data_assets(data, CHICKEN, &data->asset.chicken);
	set_data_assets(data, HOUSE, &data->asset.house);
	set_data_assets(data, LAND3_8_1, &data->asset.land_8_1);
	set_data_assets(data, LAND3_8_2, &data->asset.land_8_2);
	set_data_assets(data, LAND3_8_3, &data->asset.land_8_3);
	set_data_assets(data, LAND3_8_4, &data->asset.land_8_4);
	set_data_assets(data, LAND3_8_5, &data->asset.land_8_5);
	set_data_assets(data, LAND3_9_1, &data->asset.land_9_1);
	set_data_assets(data, LAND3_9_2, &data->asset.land_9_2);
	set_data_assets(data, LAND3_9_3, &data->asset.land_9_3);
	set_data_assets(data, LAND3_9_4, &data->asset.land_9_4);
	set_data_assets(data, LAND3_9_5, &data->asset.land_9_5);
	set_data_assets(data, LAND4_10_1, &data->asset.land_10_1);
	set_data_assets(data, LAND4_10_2, &data->asset.land_10_2);
	set_data_assets(data, LAND4_10_3, &data->asset.land_10_3);
	set_data_assets(data, LAND4_10_4, &data->asset.land_10_4);
	set_data_assets(data, LAND4_11_3, &data->asset.land_11_3);
	set_data_assets(data, LAND4_11_4, &data->asset.land_11_4);
	set_data_assets(data, EGG, &data->asset.egg);
	set_data_assets(data, CHAR_DOWN, &data->asset.char_down);
	set_data_assets(data, CHAR_UP, &data->asset.char_up);
	set_data_assets(data, CHAR_LEFT, &data->asset.char_left);
	set_data_assets(data, CHAR_RIGHT, &data->asset.char_right);
	set_data_assets(data, EIGHT, &data->asset.eight);
	set_data_assets(data, NINE, &data->asset.nine);
}

void	init_1(t_data *data)
{
	set_data_assets(data, WATER, &data->asset.water);
	set_data_assets(data, LAND_T_L, &data->asset.t_l_land);
	set_data_assets(data, LAND_T_M, &data->asset.t_m_land);
	set_data_assets(data, LAND_T_R, &data->asset.t_r_land);
	set_data_assets(data, LAND_M_L, &data->asset.m_l_land);
	set_data_assets(data, LAND_M_M, &data->asset.m_m_land);
	set_data_assets(data, LAND_M_R, &data->asset.m_r_land);
	set_data_assets(data, LAND_D_L, &data->asset.d_l_land);
	set_data_assets(data, LAND_D_M, &data->asset.d_m_land);
	set_data_assets(data, LAND_D_R, &data->asset.d_r_land);
	set_data_assets(data, LAND2_D_M, &data->asset.d_m_land2);
	set_data_assets(data, LAND2_M_L, &data->asset.m_l_land2);
	set_data_assets(data, LAND2_M_M, &data->asset.m_m_land2);
	set_data_assets(data, LAND2_M_R, &data->asset.m_r_land2);
	set_data_assets(data, LAND2_M, &data->asset.m_land2);
	set_data_assets(data, LAND2_MID, &data->asset.mid_land2);
	set_data_assets(data, LAND2_T_M, &data->asset.t_m_land2);
	set_data_assets(data, ZERO, &data->asset.zero);
	set_data_assets(data, ONE, &data->asset.one);
	set_data_assets(data, TWO, &data->asset.two);
	set_data_assets(data, THREE, &data->asset.three);
	set_data_assets(data, FOUR, &data->asset.four);
	set_data_assets(data, FIVE, &data->asset.five);
	set_data_assets(data, SIX, &data->asset.six);
	set_data_assets(data, SEVEN, &data->asset.seven);
}

void	init_2(t_data *data)
{
	set_data_assets(data, LAND3_5_1, &data->asset.land_5_1);
	set_data_assets(data, LAND3_5_2, &data->asset.land_5_2);
	set_data_assets(data, LAND3_5_3, &data->asset.land_5_3);
	set_data_assets(data, LAND3_5_4, &data->asset.land_5_4);
	set_data_assets(data, LAND3_5_5, &data->asset.land_5_5);
	set_data_assets(data, LAND3_6_1, &data->asset.land_6_1);
	set_data_assets(data, LAND3_6_2, &data->asset.land_6_2);
	set_data_assets(data, LAND3_6_3, &data->asset.land_6_3);
	set_data_assets(data, LAND3_6_4, &data->asset.land_6_4);
	set_data_assets(data, LAND3_6_5, &data->asset.land_6_5);
	set_data_assets(data, LAND3_7_1, &data->asset.land_7_1);
	set_data_assets(data, LAND3_7_2, &data->asset.land_7_2);
	set_data_assets(data, LAND3_7_3, &data->asset.land_7_3);
	set_data_assets(data, LAND3_7_4, &data->asset.land_7_4);
	set_data_assets(data, LAND3_7_5, &data->asset.land_7_5);
}

void	init_assets(t_data *data)
{
	init_1(data);
	init_2(data);
	init_3(data);
	init_char(data);
	init_style(data);
}

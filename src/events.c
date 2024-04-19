/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:29:02 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/15 15:23:27 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_destroy_4(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 3)
		mlx_destroy_image(data->mlx_ptr, data->asset.g_style[i].img);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(data->mlx_ptr, data->asset.w_style[i].img);
	i = -1;
	while (++i < 2)
		mlx_destroy_image(data->mlx_ptr, data->asset.char_down_tab[i].img);
	mlx_destroy_image(data->mlx_ptr, data->asset.char_down.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.char_left.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.char_right.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.char_up.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.zero.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.one.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.two.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.three.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.four.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.five.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.six.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.seven.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.eight.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.nine.img);
}

void	on_destroy_3(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->asset.house.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.egg.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_6_1.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_6_2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_6_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_6_4.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_6_5.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_7_1.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_7_2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_7_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_7_4.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_7_5.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_8_1.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_8_2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_8_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_8_4.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_8_5.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_9_1.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_9_2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_9_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_9_4.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_9_5.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_10_1.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_11_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_11_4.img);
}

void	on_destroy_2(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->asset.water.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.t_l_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.t_m_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.t_r_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_l_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_m_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_r_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.d_l_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.d_m_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.d_r_land.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.d_m_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_l_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_m_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_r_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.m_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.mid_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.t_m_land2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_5_1.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_5_2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_5_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_5_4.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_5_5.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_10_2.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_10_3.img);
	mlx_destroy_image(data->mlx_ptr, data->asset.land_10_4.img);
}

int	on_destroy(t_data *data)
{
	int	i;

	i = -1;
	on_destroy_2(data);
	on_destroy_3(data);
	on_destroy_4(data);
	mlx_destroy_image(data->mlx_ptr, data->asset.chicken.img);
	while (++i < 2)
		mlx_destroy_image(data->mlx_ptr, data->asset.char_up_tab[i].img);
	i = -1;
	while (++i < 2)
		mlx_destroy_image(data->mlx_ptr, data->asset.char_left_tab[i].img);
	i = -1;
	while (++i < 2)
		mlx_destroy_image(data->mlx_ptr, data->asset.char_right_tab[i].img);
	i = -1;
	mlx_destroy_image(data->mlx_ptr, data->img_dup.img);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	while (data->map[++i])
		free(data->map[i]);
	return (free(data->mlx_ptr), free(data->map), free(data->tab), exit(0), 0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == 65307)
		on_destroy(data);
	if (keysym == UP || keysym == DOWN || keysym == LEFT || keysym == RIGHT)
		ft_move_player(keysym, data);
	return (0);
}

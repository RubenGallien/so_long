/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:18:41 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 15:28:33 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "so_long.h"

typedef struct s_img
{
	void				*img;
	unsigned char		*pixels;
	int					line_length;
	int					bits_per_pixel;
	int					endian;
	int					height;
	int					width;
}									t_img;

typedef struct s_asset
{
	t_img	zero;
	t_img	one;
	t_img	two;
	t_img	three;
	t_img	four;
	t_img	five;
	t_img	six;
	t_img	seven;
	t_img	eight;
	t_img	nine;
	t_img	g_style[3];
	t_img	w_style[3];
	t_img	water;
	t_img	egg;
	t_img	t_l_land;
	t_img	t_m_land;
	t_img	t_r_land;
	t_img	m_l_land;
	t_img	m_m_land;
	t_img	m_r_land;
	t_img	d_l_land;
	t_img	d_m_land;
	t_img	d_r_land;
	t_img	d_m_land2;
	t_img	m_l_land2;
	t_img	m_m_land2;
	t_img	m_r_land2;
	t_img	m_land2;
	t_img	mid_land2;
	t_img	t_m_land2;
	t_img	land_5_1;
	t_img	land_5_2;
	t_img	land_5_3;
	t_img	land_5_4;
	t_img	land_5_5;
	t_img	land_6_1;
	t_img	land_6_2;
	t_img	land_6_3;
	t_img	land_6_4;
	t_img	land_6_5;
	t_img	land_7_1;
	t_img	land_7_2;
	t_img	land_7_3;
	t_img	land_7_4;
	t_img	land_7_5;
	t_img	land_8_1;
	t_img	land_8_2;
	t_img	land_8_3;
	t_img	land_8_4;
	t_img	land_8_5;
	t_img	land_9_1;
	t_img	land_9_2;
	t_img	land_9_3;
	t_img	land_9_4;
	t_img	land_9_5;
	t_img	land_10_1;
	t_img	land_10_2;
	t_img	land_10_3;
	t_img	land_10_4;
	t_img	land_11_3;
	t_img	land_11_4;
	t_img	house;
	t_img	chicken;
	t_img	char_up;
	t_img	char_down;
	t_img	char_right;
	t_img	char_left;
	t_img	char_right_tab[2];
	t_img	char_left_tab[2];
	t_img	char_down_tab[2];
	t_img	char_up_tab[2];
}	t_asset;

typedef struct s_player
{
	float	index[2];
	int		x;
	int		y;
	int		c;
	int		c_max;
	int		step;
	int		keysim;
	int		finish;
	t_img	lastpos;
}			t_player;

typedef struct s_monster
{
	int			x;
	int			y;
	int			active;
	long int	chrono;
	float		pos[2];
}	t_monster;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*tab;
	int			*design;
	t_asset		asset;
	t_img		img;
	t_img		img_dup;
	t_img		img_dup_2;
	int			x;
	int			y;
	time_t		time;
	char		**map;
	t_player	player;
	t_monster	monster;
}			t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

#endif
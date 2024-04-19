/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:10:58 by rgallien          #+#    #+#             */
/*   Updated: 2024/04/19 15:29:40 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "define.h"
# include "structure.h"
# include <time.h>
# include <sys/time.h>
# include <math.h>
# include <string.h>

int			verif_map(char *_file, t_data *data);
char		**ft_mapping(char *_file);
int			get_last_line(int fd, char *_file);
int			*get_x_y(char *_file, char	*asset);
void		is_possible(t_data *data);
char		**cpy_map(t_data *data);
void		find_p(char **map, t_pos *pos);
void		ft_free_tab(char **tab);
void		fill_left(char **map, int x, int y);
void		fill_right(char **map, int x, int y);
void		fill_up(char **map, int x, int y);
void		fill_down(char **map, int x, int y);
int			on_destroy(t_data *data);
void		print_error(int e, int p, int c, char *line);
int			set_data_assets(t_data *data, char *_path, t_img *asset);
int			on_keypress(int keysym, t_data *data);
void		main_display(t_data *data, int width, int height);
void		init_assets(t_data *data);
int			draw_sprite(t_img asset, t_img *img, int x, int y);
void		ft_sense(t_data *data, int i, int j, t_img *img);
void		ft_2_2_1_3(t_data *data, int i, int j, t_img *img);
void		ft_2_2_1_3_aux(t_data *data, int i, int j, t_img *img);
void		ft_2_2_0_4(t_data *data, int i, int j, t_img *img);
void		ft_3_1_1_3(t_data *data, int i, int j, t_img *img);
void		ft_3_1_2_2(t_data *data, int i, int j, t_img *img);
void		ft_3_1_0_4(t_data *data, int i, int j, t_img *img);
void		ft_4_0_3_1(t_data *data, int i, int j, t_img *img);
void		ft_4_0_2_2(t_data *data, int i, int j, t_img *img);
void		ft_4_0_1_3(t_data *data, int i, int j, t_img *img);
void		ft_1_3_0_4(t_data *data, int i, int j, t_img *img);
void		ft_2_2_aux(t_data *data, int i, int j, t_img *img);
void		ft_3_1_0_4(t_data *data, int i, int j, t_img *img);
void		put_for_3_1_aux(t_data *data, int i, int j, t_img *img);
void		ft_3_1_other(t_data *data, int i, int j, t_img *img);
void		ft_3_1_2_2_aux(t_data *data, int i, int j, t_img *img);
void		ft_3_1_3_1_aux(t_data *data, int i, int j, t_img *img);
void		ft_3_1_2_2_except(t_data *data, int i, int j, t_img *img);
int			*get_tab(t_data *data, int i, int j);
void		fill_player(t_data *data, t_img *img, t_player *player);
void		fill_collectibles(t_data *data, t_img *img);
void		fill_exit(t_data *data, t_img *img);
int			ft_move_player(int keysim, t_data *data);
void		fill_style(t_data *data, t_img *img, int i, int j);
void		init_char(t_data *data);
void		draw_step_aux(t_data *data, t_img *img, char *step, int *tab);
int			animation(t_data *data);
void		last_position(t_data *data, int keysim);
void		draw_step(t_data *data, t_img *img, char *step);
void		init_monster(t_data *data);
void		check_active(t_data *data);
long int	get_current_time(void);
void		ending(t_data *data, int keysim);

#endif
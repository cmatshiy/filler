/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:39:55 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/08/20 12:45:50 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>

# include "libft.h"

typedef struct	s_grid
{
	char		**map;
	char		**new_map;
	int			x;
	int			y;
	int			tok_x;
	int			tok_y;
	int			tok_x_b;
	int			tok_y_b;
}				t_grid;

typedef struct	s_valid
{
	int			x;
	int			y;
	int			weight;
}				t_valid;

typedef struct	s_info
{
	t_grid		board;
	t_grid		token;
	char		player;
	int			pnum;
	char		p2;
	t_valid		*link;
	int			link_c;
	t_valid		*pos;
	int			pos_c;
	int			turns;
	int			op_x;
	int			op_y;
	int			st_x;
	int			st_y;
	float		ideal_dist;
}				t_info;

void			get_input(t_info *info);
void			get_available_coords(t_info *info);
t_grid			new_grid(char **map, int x, int y);
t_valid			new_pos(int x, int y, int weight);
void			init_info(t_info *info);
int				place_token(t_info *info);
void			print_coord(t_valid coord, t_info *info);
void			cleanup(t_info *info);
void			get_player(t_info *info);
void			trim_token(t_info *info);
void			free_grid(t_grid *grid);
float			ideal_dist(t_info *map);
int				closest_index(t_info *info);
int				get_next_line(int const fd, char **line);
#endif

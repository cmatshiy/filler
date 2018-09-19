/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:20:13 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/08/20 13:04:44 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_grid(t_grid *grid)
{
	int	y;

	y = 0;
	while (y < grid->y)
	{
		if (grid->map[y] != NULL)
			free(grid->map[y]);
		y++;
	}
	free(grid->map);
}

void	cleanup(t_info *info)
{
	free_grid(&info->board);
	free_grid(&info->token);
	if (info->link != NULL)
	{
		free(info->link);
		info->link = NULL;
	}
	if (info->pos != NULL)
	{
		free(info->pos);
		info->pos = NULL;
	}
	info->pos_c = 0;
	info->link_c = 0;
}

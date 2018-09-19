/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:41:33 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/08/20 13:19:24 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*str_cut(char *str, int start, int end)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * end - start);
	while (start < end)
	{
		tmp[i] = str[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	gen_new_token(t_info *info)
{
	char	**token;
	int		y;
	int		x;
	int		i;

	y = info->token.tok_y;
	i = 0;
	token = (char **)malloc(sizeof(char *) * (info->token.tok_y_b - y + 1));
	while (y < info->token.tok_y_b + 1)
	{
		x = info->token.tok_x;
		token[i] = str_cut(info->token.map[y], x, info->token.tok_x_b + 1);
		y++;
		i++;
	}
	free_grid(&info->token);
	info->token.map = token;
	info->token.x = info->token.tok_x_b - info->token.tok_x + 1;
	info->token.y = info->token.tok_y_b - info->token.tok_y + 1;
}

void	trim_token(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info->token.y)
	{
		x = 0;
		while (x < info->token.x)
		{
			if (info->token.map[y][x] == '*')
			{
				if (x < info->token.tok_x)
					info->token.tok_x = x;
				if (y < info->token.tok_y)
					info->token.tok_y = y;
				if (x > info->token.tok_x_b)
					info->token.tok_x_b = x;
				if (y > info->token.tok_y_b)
					info->token.tok_y_b = y;
			}
			x++;
		}
	}
	if (info->token.tok_x || info->token.tok_y)
		gen_new_token(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:55:51 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/08/20 13:14:19 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		openfile(char *file)
{
	return (open(file, O_RDWR | O_APPEND));
}

void	puttrace(char *file, char *str, int fd)
{
	if (fd != -1)
	{
		ft_putendl_fd(str, fd);
	}
}

void	puttracen(char *file, char *str, int num, int fd)
{
	if (fd != -1)
	{
		ft_putstr_fd(str, fd);
		ft_putstr_fd(" : ", fd);
		ft_putnbr_fd(num, fd);
		ft_putchar_fd('\n', fd);
	}
}

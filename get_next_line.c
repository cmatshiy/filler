/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:18:02 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/08/21 08:14:44 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	swapnfree(char **variable, char *new_val)
{
	char	*tmp;

	free(*variable);
	tmp = new_val;
	*variable = tmp;
}

static int	index_of(const char *s, const char c)
{
	int j;

	j = 0;
	if (s != NULL)
	{
		while (s[j] != '\0')
		{
			if (s[j] == c)
				return (j);
			j++;
		}
		if (s[j] == c)
			return (j);
	}
	return (-1);
}

static void	work(char **ret_line, char **buffer, int nl)
{
	char	*tmp;

	tmp = ft_strsub(*buffer, 0, nl + 1);
	tmp[nl] = '\0';
	swapnfree(ret_line, ft_strjoin(*ret_line, tmp));
	free(tmp);
	tmp = ft_strsub(*buffer, nl + 1, BUFF_SIZE);
	tmp[BUFF_SIZE - nl] = '\0';
	ft_memmove(*buffer, tmp, ft_strlen(tmp) + 1);
	if (buffer[0][0] == '\0')
		ft_bzero(*buffer, (size_t)(BUFF_SIZE + 1));
	free(tmp);
}

static int	gnl(const int fd, char **ret_line, char **buffer)
{
	int		read_ret;
	int		nl;

	nl = -1;
	read_ret = 3;
	while (nl == -1 && read_ret > 0)
	{
		nl = index_of(*buffer, '\n');
		if (nl != -1)
			work(ret_line, buffer, nl);
		else
		{
			swapnfree(ret_line, ft_strjoin(*ret_line, *buffer));
			ft_bzero(*buffer, (size_t)(BUFF_SIZE + 1));
			if ((read_ret = read(fd, *buffer, BUFF_SIZE)) < 0)
				return (-1);
			buffer[0][read_ret] = '\0';
		}
	}
	return (read_ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffer[MI];
	int			read_ret;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buffer[fd], 0) < 0)
		return (-1);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(BUFF_SIZE + 1);
	if ((*line = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	if (buffer[fd][0] == '\0')
	{
		if ((read_ret = read(fd, buffer[fd], BUFF_SIZE)) <= 0)
			return (read_ret);
		buffer[fd][read_ret] = '\0';
	}
	read_ret = gnl(fd, line, &buffer[fd]);
	if (read_ret < 0)
		return (-1);
	if (line[0][0] == '\0' && read_ret == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	return (1);
}

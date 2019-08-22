/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:38:53 by tjuzen            #+#    #+#             */
/*   Updated: 2018/11/26 17:34:07 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	charctox(char *str, char c, char x)
{
	while (*str != x && *str)
	{
		if (*str == c)
			*str = x;
		str++;
	}
}

int		newline(char *str, char **line)
{
	char	*tmp;

	if (!(tmp = ft_strdup(str)))
		return (-1);
	str = ft_strcpy(str, ft_strchr(str, '\n') + 1);
	charctox(tmp, '\n', '\0');
	if (!(*line = ft_strjoin(*line, tmp)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

int		nextline(char *str, char **line)
{
	int		b;
	static char	*tmp;

	if (!(ft_strrchr(str, '\n')))
	{
		tmp = str;
		ft_strdel(line);
		*line = tmp;
		tmp = NULL;
		b = BUFF_SIZE;
		while (b--)
			str[b] = 0;
		return (0);
	}
	else
		newline(str, line);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0 ||
			(!(*line = ft_strnew(BUFF_SIZE))) ||
			fd > OPEN_MAX)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (nextline(str[fd], line))
		return (1);
	while ((ret = read(fd, str[fd], BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		if (nextline(str[fd], line))
			return (1);
	}
	return (**line == 0) ? 0 : 1;
}

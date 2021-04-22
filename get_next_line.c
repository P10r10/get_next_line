/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:06:21 by alsantia          #+#    #+#             */
/*   Updated: 2021/03/10 18:14:45 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_part(char *file_line)
{
	char *nl_pos;
	char *tmp;

	nl_pos = ft_strchr(file_line, '\n');
	tmp = ft_substr(file_line, 0, nl_pos - file_line);
	free(file_line);
	return (tmp);
}

char	*second_part(char *file_line)
{
	char *tmp;

	if (ft_strchr(file_line, '\n'))
		tmp = ft_strdup(file_line +
			(ft_strchr(file_line, '\n') - file_line) + 1);
	else
		tmp = NULL;
	return (tmp);
}

char	*join_buffer(char *file_line, char *buffer)
{
	char *tmp;

	tmp = ft_strjoin(file_line, buffer);
	free(file_line);
	file_line = ft_strdup(tmp);
	free(tmp);
	return (file_line);
}

int		get_next_line(int fd, char **line)
{
	static char	*file_line[1024];
	int			ret;
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	ret = 1;
	while (!ft_strchr(file_line[fd], '\n') && ret)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		file_line[fd] = join_buffer(file_line[fd], buffer);
	}
	tmp = second_part(file_line[fd]);
	*line = first_part(file_line[fd]);
	file_line[fd] = tmp;
	return (ret > 0);
}

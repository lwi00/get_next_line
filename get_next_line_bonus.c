
#include "get_next_line_bonus.h"

char	*read_and_append(int fd, char *remainder)
{
	char	*buf;
	int		ret;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(remainder, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(remainder);
			return (NULL);
		}
		buf[ret] = '\0';
		remainder = ft_strjoin_free(remainder, buf);
	}
	free(buf);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainders[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	remainders[fd] = read_and_append(fd, remainders[fd]);
	if (!remainders[fd] || remainders[fd][0] == '\0')
	{
		free(remainders[fd]);
		remainders[fd] = NULL;
		return (NULL);
	}
	line = extract_line(&remainders[fd]);
	return (line);
}

void	copy_and_join(char *dest, const char *src, size_t *index)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}
}

char	*extract_line(char **remainder)
{
	char	*line;
	char	*temp;
	size_t	len;

	len = 0;
	if (!*remainder || **remainder == '\0')
		return (NULL);
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
		len++;
	line = ft_substr(*remainder, 0, len);
	temp = ft_strdup((*remainder) + len);
	free(*remainder);
	*remainder = temp;
	return (line);
}

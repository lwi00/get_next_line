
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_and_append(fd, remainder);
	if (!remainder || remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(&remainder);
	return (line);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
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

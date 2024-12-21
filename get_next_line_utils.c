
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
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

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	index;

	len1 = 0;
	len2 = 0;
	index = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	if (s1)
		copy_and_join(joined, s1, &index);
	if (s2)
		copy_and_join(joined, s2, &index);
	joined[index] = '\0';
	free(s1);
	return (joined);
}

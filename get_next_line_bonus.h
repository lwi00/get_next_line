
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*extract_line(char **remainder);
char	*read_and_append(int fd, char *remainder);
void	copy_and_join(char *dest, const char *src, size_t *index);

#endif

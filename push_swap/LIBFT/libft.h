#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	**freeresult(size_t i, char **result);

#endif
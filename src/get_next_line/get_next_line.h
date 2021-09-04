#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int len);
int		ft_strlen(const char *s);
int		ft_del_all(char **rem, char *buff, int st);
int		ft_strlcpy(char *dst, const char *src, int dstsize);

#endif
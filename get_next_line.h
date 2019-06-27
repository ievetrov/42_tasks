#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 9999
# define MAX_FD 1024

int get_next_line(const int fd, char **line);

#endif

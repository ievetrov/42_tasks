#include "get_next_line.h"

static int			split_cache_str(char **p_cache_str, char **line)
{
	char			*after_endline;
	char			*cache_str;
	int				i;

	i = 0;
	cache_str = *p_cache_str;
	while (cache_str[i] != '\n')
	{
		if (cache_str[i] == '\0')
		{
			return (0);
		}
		i++;
	}

	after_endline = &cache_str[i];
	*after_endline = '\0';
	*line = ft_strdup(*p_cache_str);
	*p_cache_str = ft_strdup(after_endline + 1);
	return (1);
}

static	int			read_fd(int fd, char **cache, char **line)
{
	int				ret;
	char			*tmp_cache;
	char			buffer[BUFF_SIZE];

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (*cache)
		{
			tmp_cache = *cache;
			*cache = ft_strjoin(tmp_cache, buffer);
			free(tmp_cache);
			tmp_cache = NULL;
		}
		else
		{
			*cache = ft_strdup(buffer);
		}
		if (split_cache_str(cache, line))
			break ;
	}
	return (ret > 0 ? 1 : ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*cache[MAX_FD];
	int				ret;

	if (!line || (fd < 0 || fd >= MAX_FD))
		return (-1);
	if (cache[fd] != NULL)
		if (split_cache_str(&cache[fd], line))
			return (1);

	ret = read_fd(fd, &cache[fd], line);

	if (ret != 0 || cache[fd] == NULL || cache[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = cache[fd];
	cache[fd] = NULL;
	return (1);
}

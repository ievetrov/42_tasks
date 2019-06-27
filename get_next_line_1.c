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
			return (0); // 0 - если кэш-строка без переносов внутри себя
        }
        i++;
    }

    // в line пишет все символы до \n
    // в p_cache_str остальное

    after_endline = &cache_str[i];
	*after_endline = '\0';
	*line = ft_strdup(*p_cache_str);
	*p_cache_str = ft_strdup(after_endline + 1);
	return (1); // 1 - если кэш-строка с переносом и была обрезана
}

static	int			read_fd(int fd, char *buffer, char **cache, char **line)
{
	int				ret;
	char			*tmp_cache;

    // читаем пока не наступит EOF
    // (read вернет значение меньшее чем мы просили)
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
	char			*buffer;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD))
		return (-1);

    // if (read(fd, cache[fd], 0) < 0) // проверка что файл еще существует
    //    return (-1);

    if(!(buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
        return (-1);

	if (cache[fd] != NULL)
		if (split_cache_str(&cache[fd], line))
			return (1);

    // заполняем нулями буфер
    i = 0;
	while (i < BUFF_SIZE)
		buffer[i++] = '\0';

    ret = read_fd(fd, buffer, &cache[fd], line);

    free(buffer);

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

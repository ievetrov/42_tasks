#include "get_next_line.h"

int main(void)
{
	/* Получение файлового дескриптора */
	int fd1 = open("testfile.1.txt", O_RDONLY);
	int fd2 = open("testfile.2.txt", O_RDONLY);
	// if (fd < 0)
	// {
	// 	printf("ERROR");
	// 	return 1;
	// }

	char *line;


	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	

	// /* читаем все строки */
	// while(get_next_line(fd, &line) > 0)
    // {
	// 	printf("%s\n", line);
	// 	free(line);
	// 	// line = NULL;
    // }

	close(fd1);
	close(fd2);
	return (0);
}

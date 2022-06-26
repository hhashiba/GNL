// #include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	int		fd7;
	int		fd8;
	int		fd9;
	int		fd10;
	int		fd11;
	int		fd12;
	int		fd13;
	int		fd14;
	int		fd15;
	int		fd16;
	int		fd17;
	int		fd18;
	int		fd19;
	int		fd20;
	int		fd21;
	char	*line;

	fd1 = open("./tests/41_no_nl", O_RDONLY);
	fd2 = open("./tests/41_with_nl", O_RDONLY);
	fd3 = open("./tests/42_no_nl", O_RDONLY);
	fd4 = open("./tests/42_with_nl", O_RDONLY);
	fd5 = open("./tests/43_no_nl", O_RDONLY);
	fd6 = open("./tests/43_with_nl", O_RDONLY);
	fd7 = open("./tests/alternate_line_nl_no_nl", O_RDONLY);
	fd8 = open("./tests/alternate_line_nl_with_nl", O_RDONLY);
	fd9 = open("./tests/big_line_no_nl", O_RDONLY);
	fd10 = open("./tests/big_line_with_nl", O_RDONLY);
	fd11 = open("./tests/empty", O_RDONLY);
	fd12 = open("./tests/multiple_line_no_nl", O_RDONLY);
	fd13 = open("./tests/multiple_line_with_nl", O_RDONLY);
	fd14 = open("./tests/multiple_nlx5", O_RDONLY);
	fd15 = open("./tests/nl", O_RDONLY);
	fd16 = open("./tests/aaa", O_RDONLY);
	fd17 = open("./tests/bbb", O_RDONLY);
	fd18 = open("./tests/ccc", O_RDONLY);
	fd19 = open("./tests/ddd", O_RDONLY);
	fd20 = open("./tests/eee", O_RDONLY);
	fd21 = open("./tests/fff", O_RDONLY);

	printf("\n------FIRST-------\n");
	printf("\n--------fd1--------\n");
	line = get_next_line(fd1);
	printf("fd = %d %s", fd1, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd2);
	printf("\n--------fd2--------\n");
	printf("fd = %d %s", fd2, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd3);
	printf("\n--------fd3--------\n");
	printf("fd = %d %s", fd3, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd4);
	printf("\n--------fd4--------\n");
	printf("fd = %d %s", fd4, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd5);
	printf("\n--------fd5--------\n");
	printf("fd = %d %s", fd5, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd6);
	printf("\n--------fd6--------\n");
	printf("fd = %d %s", fd6, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd7);
	printf("\n--------fd7--------\n");
	printf("fd = %d %s", fd7, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd8);
	printf("\n--------fd8--------\n");
	printf("fd = %d %s", fd8, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd9);
	printf("\n--------fd9--------\n");
	printf("fd = %d %s", fd9, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd10);
	printf("\n--------fd10--------\n");
	printf("fd = %d %s", fd10, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd11);
	printf("\n--------fd11--------\n");
	printf("fd = %d %s", fd11, line);
	free(line);
	line = get_next_line(fd12);
	printf("\n--------fd12-------\n");
	printf("fd = %d %s", fd12, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd13);
	printf("\n--------fd13-------\n");
	printf("fd = %d %s", fd13, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd14);
	printf("\n--------fd14-------\n");
	printf("fd = %d %s", fd14, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd15);
	printf("\n--------fd15-------\n");
	printf("fd = %d %s", fd15, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd16);
	printf("\n--------fd16-------\n");
	printf("fd = %d %s", fd16, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd17);
	printf("\n--------fd17-------\n");
	printf("fd = %d %s", fd17, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd18);
	printf("\n--------fd18-------\n");
	printf("fd = %d %s", fd18, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd19);
	printf("\n--------fd19-------\n");
	printf("fd = %d %s", fd19, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd20);
	printf("\n--------fd20-------\n");
	printf("fd = %d %s", fd20, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd21);
	printf("\n--------fd21-------\n");
	printf("fd = %d %s", fd21, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	printf("\n------SECOND-------\n");
	printf("\n--------fd1-------\n");
	line = get_next_line(fd1);
	printf("fd = %d %s", fd1, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd2);
	printf("\n--------fd2--------\n");
	printf("fd = %d %s", fd2, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd3);
	printf("\n--------fd3--------\n");
	printf("fd = %d %s", fd3, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd4);
	printf("\n--------fd4--------\n");
	printf("fd = %d %s", fd4, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd5);
	printf("\n--------fd5--------\n");
	printf("fd = %d %s", fd5, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd6);
	printf("\n--------fd6--------\n");
	printf("fd = %d %s", fd6, line);
	free(line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	line = get_next_line(fd7);
	printf("\n--------fd7--------\n");
	printf("fd = %d %s", fd7, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd8);
	printf("\n--------fd8--------\n");
	printf("fd = %d %s", fd8, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd9);
	printf("\n--------fd9--------\n");
	printf("fd = %d %s", fd9, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd10);
	printf("\n--------fd10--------\n");
	printf("fd = %d %s", fd10, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd11);
	printf("\n--------fd11--------\n");
	printf("fd = %d %s", fd11, line);
	free(line);
	line = get_next_line(fd12);
	printf("\n--------fd12-------\n");
	printf("fd = %d %s", fd12, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd13);
	printf("\n--------fd13-------\n");
	printf("fd = %d %s", fd13, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd14);
	printf("\n--------fd14-------\n");
	printf("fd = %d %s", fd14, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd15);
	printf("\n--------fd15-------\n");
	printf("fd = %d %s", fd15, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd16);
	printf("\n--------fd16-------\n");
	printf("fd = %d %s", fd16, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd17);
	printf("\n--------fd17-------\n");
	printf("fd = %d %s", fd17, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd18);
	printf("\n--------fd18-------\n");
	printf("fd = %d %s", fd18, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd19);
	printf("\n--------fd19-------\n");
	printf("fd = %d %s", fd19, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd20);
	printf("\n--------fd20-------\n");
	printf("fd = %d %s", fd20, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);
	line = get_next_line(fd21);
	printf("\n--------fd21-------\n");
	printf("fd = %d %s", fd21, line);
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7);
	close(fd8);
	close(fd9);
	close(fd10);
	close(fd11);
	close(fd12);
	close(fd13);
	close(fd14);
	close(fd15);
	close(fd16);
	close(fd17);
	close(fd18);
	close(fd19);
	close(fd20);
	close(fd21);
	return (0);
}

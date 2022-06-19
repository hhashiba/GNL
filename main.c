#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdbool.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./tests/files/empty", O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}

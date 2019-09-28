//
// Created by Protection Melodi on 28/09/2019.
//

#include "get_next_line.h"

#include <stdio.h>

int				main(void)
{
	int		fd;
	char 	*line;
	int 	one;
	int		i;

	i = 5;
	one = 0;
	if ((fd = open("/Users/pmelodi/Projects/GetNextLine/gnl1_3.txt", O_RDONLY)) == -1)
		ft_putendl("File error!");
	while (get_next_line(fd, &line) > 0)
	{

		printf("%s\n", line);
		free(line);
	}
	close(fd);

//	if ((fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY)) == -1)
//		ft_putendl("File error!");
//
//	printf("%d\n", get_next_line(fd, &line));
//	printf("%s\n", line);
//	free(line);
//
//	close(fd);
	return (0);
}

//fd = open("/Users/pmelodi/Projects/GetNextLine/war-and-peace.txt", O_RDONLY);
//	fd = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY);
//fd = open("/Users/pmelodi/Projects/GetNextLine/gnl1_3.txt", O_RDONLY);
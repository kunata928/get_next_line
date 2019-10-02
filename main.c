//
// Created by Protection Melodi on 28/09/2019.
//

#include "get_next_line.h"
#include <stdio.h>

int				main(void)
{
	int		fd1;
	int		fd2;
	char 	*line;

	if ((fd1 = open("/Users/pmelodi/Projects/GetNextLine/gnl1_3.txt", O_RDONLY)) == -1)
		ft_putendl("File error!");
	if ((fd2 = open("/Users/pmelodi/Projects/GetNextLine/readme.txt", O_RDONLY)) == -1)
		ft_putendl("File error!");
	while (get_next_line(fd2, "&line"))
	{
		printf("%s\n", line);
		ft_strdel(&line);
		//if (get_next_line(fd2, &line))
		//	printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd1);
	close(fd2);
	return (0);
}
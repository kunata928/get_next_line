cmake_minimum_required(VERSION 3.14)
project(libft)

set(CMAKE_C_STANDARD 99)

set(SOURCES ft_atoi.c ft_strcpy.c ft_strdup.c
			ft_isascii.c ft_strncpy.c ft_strcat.c
			ft_strstr.c ft_isprint.c ft_strlen.c
			ft_isalpha.c ft_isdigit.c ft_isalnum.c
			ft_toupper.c ft_tolower.c ft_strncat.c
			ft_strlcat.c ft_strchr.c ft_strrchr.c
			ft_memset.c ft_bzero.c ft_memcpy.c
			ft_memccpy.c ft_memmove.c ft_memchr.c
			ft_memcmp.c ft_strnstr.c ft_strcmp.c
			ft_strncmp.c
			ft_memalloc.c ft_memdel.c ft_strnew.c
			ft_strdel.c ft_strclr.c ft_striter.c
			ft_striteri.c ft_strmap.c ft_strmapi.c
			ft_strequ.c ft_strnequ.c ft_strsub.c
			ft_strjoin.c ft_strtrim.c ft_strsplit.c
			ft_putchar.c ft_putstr.c
			ft_iswhitespace.c ft_putnbr.c ft_putnbr_fd.c
			ft_putstr_fd.c ft_putchar_fd.c ft_putendl.c
			ft_putendl_fd.c ft_itoa.c
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c
			ft_lstadd.c ft_lstiter.c ft_lstmap.c
			ft_numlen.c ft_iterative_power.c ft_cnt_words.c
			ft_lstlen.c ft_cntchr.c)

set (HEADER libft.h)

add_library(libft STATIC ${SOURCES} libft.h)
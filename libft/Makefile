# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 09:00:26 by nramalan          #+#    #+#              #
#    Updated: 2026/03/03 17:54:42 by nramalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcpy.c ft_strlen.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
	ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
	ft_strdup.c ft_calloc.c \
	ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line_utils.c get_next_line.c

NAME := libft.a

HEADER_DIR := ../.

OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror
CC := @cc
AR := @ar crs
RM := @rm -f

.PHONY: all
all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

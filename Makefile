# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 21:40:26 by araji-af          #+#    #+#              #
#    Updated: 2022/10/28 19:37:04 by araji-af         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_M	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c


SRCS_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_M	=	$(SRCS_M:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	libft.a



all:	$(NAME)

$(NAME):	$(OBJS_M) 
	ar rc $(NAME) $(OBJS_M)

$(OBJS_M):	$(SRCS_M) libft.h
	$(CC) -c  $(CFLAGS) $(SRCS_M)

$(OBJS_B):	$(SRCS_B) libft.h
	$(CC) -c $(CFLAGS) $(SRCS_B)
clean:
	$(RM) $(OBJS_M) $(OBJS_B)

fclean:	clean
	$(RM) $(NAME)


bonus:	$(OBJS_B)
	ar rc $(NAME) $(OBJS_B)

re:		fclean all

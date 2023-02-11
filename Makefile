# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aankote <aankote@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:46:31 by aankote           #+#    #+#              #
#    Updated: 2023/02/11 10:21:47 by aankote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARC = ar -rc

FILES = pipex.c pipex_utils.c
OBJCS = $(FILES:.c=.o)

INCLUDES = libft/libft.a get_next_line/get_next_line.a

all : $(NAME)

$(NAME) : $(FILES)
	@make -C libft
	@make -C get_next_line
	@$(CC)  $(FILES) $(CFLAGS) $(INCLUDES) -o $(NAME)

bonus : $(NAME_B)

%.o:%.c
	@$(CC)  $(CFLAGS)  -c $<  -o $@
	@echo "\033[0;32m𝘾𝙧𝙚𝙖𝙩𝙞𝙣𝙜 ...\033[0m"
clean :
	@rm -fr libft/*.o && rm -fr libft/*.a
	@rm -fr get_next_line/*.o && rm -fr get_next_line/*.a
	@rm -fr $(OBJCS)
	@echo "\033[0;31m𝑶𝒃𝒋𝒆𝒄𝒕𝒔' 𝒄𝒍𝒆𝒂𝒏𝒆𝒅\033[0m"

fclean : clean
	@rm -fr $(NAME)
	@echo "\033[1;33m𝙀𝙫𝙚𝙧𝙮𝙩𝙝𝙞𝙣𝙜'𝙨 𝙘𝙡𝙚𝙖𝙣𝙚𝙙\033[0m"

re :fclean all

push :
	git add .
	git commit -m "Updated"
	git push
	echo "\033[0;32mPuched ...\033[0m"
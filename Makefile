# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aankote <aankote@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:46:31 by aankote           #+#    #+#              #
#    Updated: 2023/02/16 09:11:46 by aankote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_B = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARC = ar -rc

FILES = pipex.c pipex_utils.c

FILES_B = bonus/pipex_bonus.c bonus/pipex_utils_bonus.c

OBJCS = $(FILES:.c=.o)

OBJCS_B = $(FILES_B:.c=.o)

INCLUDES = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJCS)
	@make -C libft
	@$(CC)  $(OBJCS) $(CFLAGS) $(INCLUDES) -o $(NAME)


%.o:%.c
	@$(CC)  $(CFLAGS)  -c $<  -o $@
	@echo "\033[0;32m𝘾𝙧𝙚𝙖𝙩𝙞𝙣𝙜 ...\033[0m"
clean :
	@rm -fr libft/*.o && rm -fr libft/*.a
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
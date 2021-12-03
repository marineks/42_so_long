# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 12:17:43 by msanjuan          #+#    #+#              #
#    Updated: 2021/12/03 17:50:26 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS = 


OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx_linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = clang
CFLAGS = -Wall -Werror -Wextra # -g -MMD
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f

# /* ~~~~~~~ BONUS ~~~~~~~ */
# BONUS = 
# BONUS_DIR = ./bonus/
# BONUS_SRCS = 

# B_OBJS = ${addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.o}}

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): $(OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS) 
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

# $(BONUS): $(OBJS) $(B_OBJS)
# 	@cd $(LIBFT_DIR) && $(MAKE)
# 	@echo $(CYAN) " - Compiling $@" $(RED)
# 	@$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) $(BONUS_DIR)bonus_main.c $(IFLAGS) $(LFLAGS) -o $(BONUS)
# 	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		# @${RM} ${B_OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME} a.out
		# @${RM} ${B_OBJS} ${BONUS} a.out

re: 	fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harsh <harsh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/12/10 09:43:51 by harsh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 		= fractol
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror -MMD -MP -I./include -I./srcs/myLib/header -g
MLX_LIB		= ./MLX42/build/libmlx42.a
MLX_PATH	= ./MLX42
LIBFT_DIR 	= ./srcs/myLib
LIBFT_LIB 	= ./srcs/myLib/libft.a

OS := $(shell uname)

ifeq ($(OS), Darwin)
	MLX = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else ifeq ($(OS), Linux)
	MLX = -ldl -lglfw -pthread -lm
endif

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJDIR		= ./objs

VPATH		= .:./srcs/:./srcs/manual:./srcs/init:./srcs/colors:./srcs/hooks:./srcs/fractols

SRC			= fractol.c utils.c
SRCS_MAN	= argument_manual.c
SRCS_INIT	= init.c
SRCS_COLORS	= colors.c color_pallette.c
SRCS_HOOKS	= key_hooks.c mouse_hooks.c
SRCS_FRACTOLS = mandelbrot.c julia.c fern.c select_fractol.c
################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = $(SRC) $(SRCS_MAN) $(SRCS_COLORS) $(SRCS_INIT) $(SRCS_HOOKS) $(SRCS_FRACTOLS)
OBJS = $(addprefix $(OBJDIR)/, ${SRCS:%.c=%.o})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m # Blue
OBJ_COLOR   = \033[0;36m # Cyan
ERROR_COLOR = \033[0;31m # Red
WARN_COLOR  = \033[0;33m # Yellow
OK_COLOR    = \033[0;32m # Green
NO_COLOR    = \033[m 

COM_STRING   = "Compiling"

################################################################################
#                                 Makefile rules                             #
################################################################################

all: submodule $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cd MLX42 && cmake -B build && make -C build -j4
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR) $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX) $(LIBFT_LIB) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

submodule:
	@echo "$(COM_COLOR)Checking for MLX42 submodule...$(NO_COLOR)"
	@git submodule init && git submodule update
#	@git submodule add https://github.com/codam-coding-college/MLX42.git

clean:
	@echo
	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
	@make clean -C $(LIBFT_DIR)
	@rm -rf objs fractol
	@echo

fclean: clean
	@printf "%b" "$(COM_COLOR)Cleaning libft library...$(NO_COLOR)"
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo

norm: $(SRCS)
	$(shell norminette | grep Error)

re: fclean all

.PHONY: all clean fclean re $(LIBFT_LIB)

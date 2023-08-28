# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/08/28 17:52:07 by hkumbhan         ###   ########.fr        #
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
DEPS = $(addprefix $(OBJDIR)/, ${SRCS:%.c=%.d})

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

all: submodules $(NAME)
	@echo
	@echo "$(OBJ_COLOR)$(OS)$(NO_COLOR):  $(MLX)"

$(NAME): $(OBJS) $(LIBFT_LIB)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_LIB) $(MLX) $(LIBFT_LIB)

$(LIBFT_LIB):
	@make re -C $(LIBFT_DIR) > make_output.txt 2>&1; \
	if [ $$? -eq 0 ]; then \
		echo "$(OK_COLOR)LIBFT.A compilation successful.$(NO_COLOR)"; \
	else \
		echo "$(ERROR_COLOR)LIBFT.A compilation failed.$(NO_COLOR) Check make_output.txt for details."; \
		exit 1; \
	fi

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

submodules:
	@echo "$(COM_COLOR)Checking for MLX42 submodule...$(NO_COLOR)"
	@if [ -z "$(shell ls -A $(MLX_PATH))" ]; then \
		git submodule init $(MLX_PATH); \
		git submodule update $(MLX_PATH); \
		cd MLX42 && cmake -B build && make -C build -j4; \
	fi

clean:
	@echo
	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
	@make clean -C $(LIBFT_DIR)
	@rm -rf objs program
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

-include $(DEPS)
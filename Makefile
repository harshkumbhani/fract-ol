# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harsh <harsh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2024/07/10 11:28:26 by harsh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
###############                     CONFIG                        ##############
################################################################################

NAME := fractol
CC := cc
CFLAGS = -Wextra -Wall -Werror -MMD -MP $(addprefix -I, $(INC_DIRS))
LIBFT_DIR := ./libft
LIBFT_LIB := ./libft/libft.a
MLX_DIR	:= ./MLX42
MLX_LIB	:= ./MLX42/build/libmlx42.a

ifeq ($(shell uname), Darwin)
	MLX_FLAGS = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else ifeq ($(shell uname), Linux)
	MLX_FLAGS = -ldl -lglfw -pthread -lm
endif

################################################################################
###############                 PRINT OPTIONS                     ##############
################################################################################

G := \033[32m
X := \033[0m
BO := $(shell tput bold)
LOG := printf "[$(BO)$(G)ⓘ INFO$(X)] %s\n"

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR		:= _obj
INC_DIRS 	:= ./include ./libft/include ./MLX42/include/MLX42
SRC_DIRS 	:= ./srcs/ ./srcs/manual ./srcs/init ./srcs/colors \
				./srcs/hooks ./srcs/fractols ./srcs/utils

# Tell the Makefile where headers and source files are
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS_MAIN		:= fractol.c
SRCS_MAN		:= argument_manual.c
SRCS_INIT		:= init.c
SRCS_COLORS		:= colors.c color_pallette.c
SRCS_HOOKS		:= key_hooks.c mouse_hooks.c
SRCS_FRACTOLS 	:= mandelbrot.c julia.c fern.c select_fractol.c
SRCS_UTILS		:= utils.c

SRCS := $(SRCS_MAIN) $(SRCS_MAN) $(SRCS_COLORS) $(SRCS_INIT) \
		$(SRCS_HOOKS) $(SRCS_FRACTOLS) $(SRCS_UTILS)

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

all: submodule mlx_lib ft_lib $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Linking object files to $@"
	@$(CC) $(CFLAGS) $^ $(MLX_LIB) $(MLX_FLAGS) $(LIBFT_LIB) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $@)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating object directory."
	@mkdir -p $@

submodule:
	@git submodule update --init

mlx_lib:
	@if [ ! -f $(MLX_LIB) ]; then \
		$(LOG) "Creating mlx_lib"; \
		cd MLX42 && cmake -B build && make -C build -j4; \
	else \
		$(LOG) "mlx_lib already created"; \
	fi

ft_lib:
	@if [ ! -f $(LIBFT_LIB) ]; then \
		$(LOG) "Creating ft_lib"; \
		make -C $(LIBFT_DIR); \
	else \
		$(LOG) "ft_lib already created"; \
	fi

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(LOG) "Cleaning $(notdir $(OBJ_DIR))"; \
		rm -rf $(OBJ_DIR); \
	else \
		$(LOG) "No objects to clean."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(LOG) "Cleaning $(notdir $(NAME))"; \
		rm -f $(NAME); \
	else \
		$(LOG) "No library to clean."; \
	fi

re: fclean all

-include $(OBJS:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

.PHONY: all fclean clean re

bonus:
	@$(MAKE) BONUS=1 all


################################################################################
#                                     CONFIG                                   #
################################################################################

# NAME 		= fractol
# CC			= cc
# CFLAGS 		= -Wall -Wextra -Werror -MMD -MP -I./include -I./srcs/myLib/header -g
# MLX_LIB		= ./MLX42/build/libmlx42.a
# MLX_PATH	= ./MLX42
# LIBFT_DIR 	= ./srcs/myLib
# LIBFT_LIB 	= ./srcs/myLib/libft.a

# OS := $(shell uname)

# ifeq ($(OS), Darwin)
# 	MLX = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
# else ifeq ($(OS), Linux)
# 	MLX = -ldl -lglfw -pthread -lm
# endif

# ################################################################################
# #                                 PROGRAM'S SRCS                               #
# ################################################################################

# OBJDIR		= ./objs

# VPATH		= .:./srcs/:./srcs/manual:./srcs/init:./srcs/colors:./srcs/hooks:./srcs/fractols

# SRC			= fractol.c utils.c
# SRCS_MAN	= argument_manual.c
# SRCS_INIT	= init.c
# SRCS_COLORS	= colors.c color_pallette.c
# SRCS_HOOKS	= key_hooks.c mouse_hooks.c
# SRCS_FRACTOLS = mandelbrot.c julia.c fern.c select_fractol.c
# ################################################################################
# #                                  Makefile  objs                              #
# ################################################################################

# SRCS = $(SRC) $(SRCS_MAN) $(SRCS_COLORS) $(SRCS_INIT) $(SRCS_HOOKS) $(SRCS_FRACTOLS)
# OBJS = $(addprefix $(OBJDIR)/, ${SRCS:%.c=%.o})

# ################################################################################
# #                                 Makefile logic                               #
# ################################################################################

# COM_COLOR   = \033[0;34m # Blue
# OBJ_COLOR   = \033[0;36m # Cyan
# ERROR_COLOR = \033[0;31m # Red
# WARN_COLOR  = \033[0;33m # Yellow
# OK_COLOR    = \033[0;32m # Green
# NO_COLOR    = \033[m 

# COM_STRING   = "Compiling"

# ################################################################################
# #                                 Makefile rules                             #
# ################################################################################

# all: submodule $(NAME)

# $(NAME): $(OBJS)
# 	@make -C $(LIBFT_DIR)
# 	@cd MLX42 && cmake -B build && make -C build -j4
# 	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR) $(NO_COLOR)"
# 	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX) $(LIBFT_LIB) -o $@

# $(OBJDIR)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# submodule:
# 	@echo "$(COM_COLOR)Checking for MLX42 submodule...$(NO_COLOR)"
# 	@git submodule init && git submodule update

# clean:
# 	@echo
# 	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
# 	@make clean -C $(LIBFT_DIR)
# 	@rm -rf objs fractol
# 	@echo

# fclean: clean
# 	@printf "%b" "$(COM_COLOR)Cleaning libft library...$(NO_COLOR)"
# 	@make fclean -C $(LIBFT_DIR)
# 	@rm -f $(NAME)
# 	@echo

# norm: $(SRCS)
# 	$(shell norminette | grep Error)

# re: fclean all

# .PHONY: all clean fclean re $(LIBFT_LIB)

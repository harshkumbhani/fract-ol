# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/08/17 10:43:05 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 		= fractol
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror -MMD -MP -I./include -I./srcs/myLib/header -g
MLX_LIB		= ./MLX42/build/libmlx42.a
LIBFT_DIR 	= ./srcs/myLib
LIBFT_LIB 	= ./srcs/myLib/libft.a
# MLX			= -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
# MLX			= -ldl -lglfw -pthread -lm

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

VPATH		= .:./srcs/init:./srcs/manual

SRC			=
SRCS_MAN	= argument_manual.c
################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = fractol.c init.c $(SRCS_MAN)
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

all: $(NAME)
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

#bonus: checker

#checker: $(BONUS_OBJS) $(LIBFT_LIB)
#	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
#	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) -o $@

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
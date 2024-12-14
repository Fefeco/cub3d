# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 21:09:29 by fcarranz          #+#    #+#              #
#    Updated: 2024/12/14 21:56:45 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET 	= \033[0;39m
RED 	= \033[0;91m
GREEN	= \033[0;92m
YELLOW	= \033[0;93m
BLUE	= \033[0;94m

NAME		= cub3d
LIBFT		= libft/libftprintf.a
PHONY_LIBFT	= libftprintf.a
LIBMLX		= mlx/libmlx.a

CC			= cc
INC			= -Imlx -Iinc -Ilibft/inc
CFLAGS		= -Wall -Wextra -Werror -g -MMD
MLX_FLAGS	= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT_FLAGS	= -Llibft -lftprintf

LFT_PATH	= libft/
MLX_PATH	= mlx/
SRCS_PATH	= src/
OBJS_PATH	= obj/
DEPS_PATH	= dep/

SRCS = add_line_to_map.c \
	   exit.c \
	   extract.c \
	   extract_color.c \
	   extract_coord.c \
	   main.c \
	   map_tools.c \
	   map_validations.c \
	   print_error.c \
	   print_err.c \
	   set_params.c \
	   tests.c \
	   init.c \
	   init_structs.c \
	   switch_img.c \
	   render.c \
	   create_image.c

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS = $(addprefix $(DEPS_PATH), $(SRCS:.c=.d))

.PHONY: all clean fclean re $(PHONY_LIBFT)

all: $(PHONY_LIBFT) $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS) inc/cub3d.h
	@echo "$(YELLOW)	Compiling cub3d...\n$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(INC) -o $@
	@echo "\n$(GREEN)"
	@echo "	===============	"
	@echo "	 cub3d created	"
	@echo "	===============	"
	@echo "\n$(RESET)"


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH) $(DEPS_PATH)
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@
	@echo "$(GREEN)Creating object $(RESET)- $(BLUE)$@"
	@mv $(subst .o,.d,$@) $(DEPS_PATH)

$(LIBFT):
	@make -C $(LFT_PATH) --no-print-directory

$(PHONY_LIBFT):
	@make -C $(LFT_PATH) --no-print-directory

$(LIBMLX):
	@echo "$(YELLOW)	Compiling mlx...\n"
	@make -C mlx --no-print-directory 2> /dev/null
	@echo "\n$(GREEN)"
	@echo "	==============	"
	@echo "	 mlx created	"
	@echo "	==============	"
	@echo "\n$(RESET)"

clean:
	@if [ -d $(OBJS_PATH) ]; then \
		make clean-objects --no-print-directory; \
	else \
		make no-objects --no-print-directory; \
	fi

fclean: clean
	@if [ -f $(NAME) ] || [ -f $(LIBFT) ] ; then \
		make clean-files --no-print-directory; \
	else \
		make no-files --no-print-directory; \
	fi

clean-objects:
	@echo "\n$(YELLOW)	Removing object files...$(RESET)"
	@make clean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH) > /dev/null

	@rm -rf $(OBJS_PATH) $(DEPS_PATH)
	@echo "\n$(GREEN)"
	@echo "	======================  "
	@echo "	 All .o files removed   "
	@echo "	======================  "
	@echo "\n$(RESET)"

no-objects:
	@echo "\n$(RED)"
	@echo "	========================    "
	@echo "	 No .o files to remove. "
	@echo "	========================    "
	@echo "\n$(RESET)"

clean-files:
	@echo "\n$(YELLOW)	Removing files $(NAME) and $(LIBFT)...$(RESET)"
	@rm -f $(NAME) $(LIBFT)
	@echo "\n$(GREEN)"
	@echo "	===================	"
	@echo "	 All files removed	"
	@echo "	===================	"
	@echo "\n$(RESET)"

no-files:
	@echo "\n$(RED)"
	@echo "	=====================	"
	@echo "	 No files to remove.	"
	@echo "	=====================	"
	@echo "\n$(RESET)"

re: fclean all

-include $(DEPS)

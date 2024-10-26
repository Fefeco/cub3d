DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -Iinc
MLX_FLAGS=-Lmlx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT_FLAGS=-Llibft -l ftprintf

INC=-Imlx-linux

LIBFT_PATH=libft/
SRC_PATH = src/
OBJS_PATH = objects/
DEPS_PATH = deps/

SRCS =	main/main.c \

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS = $(addprefix $(DEPS_PATH), $(SRCS:.c=.d))

all: $(NAME)

$(NAME):  $(OBJS) inc/cub3d.h
	@echo "$(YELLOW)\n"
	@echo "Compiling cub3d...\n"
	@echo "$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(INC) -o $(NAME)
	@echo "$(GREEN)\n"
	@echo "	===============	"
	@echo "	 cub3d created	"
	@echo "	===============	"
	@echo "\n"
	@echo "$(DEF_COLOR)"


$(OBJS_PATH)%.o: $(SRC_PATH)%.c inc/cub3d.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@mkdir -p $(subst $(OBJS_PATH),$(DEPS_PATH),$(@D))
	@mv $(patsubst %.o,%.d,$@) $(subst $(OBJS_PATH),$(DEPS_PATH),$(@D))/

libfta: libft/Makefile	
	@echo "$(YELLOW)Compiling libft...\n"
	@make -C $(LIBFT_PATH) --no-print-directory
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 libft created	"
	@echo "	==============	"
	@echo "\n"

$(MLX_NAME): mlx/Makefile
	@echo "$(YELLOW)Compiling mlx...\n"
	@make -C mlx/ &> /dev/null
	@echo "$(GREEN)\n"
	@echo "	==============	"
	@echo "	 mlx created	"
	@echo "	==============	"
	@echo "\n"

clean:
	@if [ -d "$(OBJS_PATH)" ] && [ -n "$$(find $(OBJS_PATH) -name '*.o' -print -quit)" ]; then \
		echo "\n"; \
		echo "$(YELLOW)Removing object files...$(RED)"; \
		@make clean -C $(LIBFT_PATH) > /dev/null \
		@make clean -C $(MLX_PATH) > /dev/null \
		rm -rf $(OBJS_PATH) $(DEPS_PATH); \
		echo "\n"; \
		echo "	======================	"; \
		echo "	 All .o files removed	"; \
		echo "	======================	"; \
		echo "\n"; \
	else \
		echo "$(RED)\n"; \
		echo "	========================	"; \
		echo "	 No .o files to remove.	"; \
		echo "	========================	"; \
		echo "\n"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ] || [ -d "$(LIBFT_PATH)" ] && [ -n "$$(find $(LIBFT_PATH) -name '*.a' -print -quit)" ]; then \
		echo "\n"; \
		rm -rf $(NAME); \
		echo "\n"; \
		echo "	===================	"; \
		echo "	 All files removed	"; \
		echo "	===================	"; \
		echo "\n"; \
	else \
		echo "$(RED)\n"; \
		echo "	=====================	"; \
		echo "	 No files to remove.	"; \
		echo "	=====================	"; \
		echo "\n"; \
	fi

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 13:06:50 by davifer2          #+#    #+#              #
#    Updated: 2024/12/02 15:26:39 by fedeito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR =		\033[0;39m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m

NAME = libftprintf.a

CC = cc 
INC = -Iinc
CFLAGS = -Wall -Werror -Wextra -MMD -g

SRCS_PATH = src/
OBJS_PATH = objs/
DEPS_PATH = deps/

LFT_SRC_PATH = $(SRCS_PATH)lft/
LFT_OBJ_PATH = $(subst $(SRCS_PATH), $(OBJS_PATH), $(LFT_SRC_PATH))
LFT_DEP_PATH = $(subst $(SRCS_PATH), $(DEPS_PATH), $(LFT_SRC_PATH))

GNL_SRC_PATH = $(SRCS_PATH)gnl/
GNL_OBJ_PATH = $(subst $(SRCS_PATH), $(OBJS_PATH), $(GNL_SRC_PATH))
GNL_DEP_PATH = $(subst $(SRCS_PATH), $(DEPS_PATH), $(GNL_SRC_PATH))

PRF_SRC_PATH = $(SRCS_PATH)printf/
PRF_OBJ_PATH = $(subst $(SRCS_PATH), $(OBJS_PATH), $(PRF_SRC_PATH))
PRF_DEP_PATH = $(subst $(SRCS_PATH), $(DEPS_PATH), $(PRF_SRC_PATH))

LFT_FILES = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c	\
			ft_lstlast_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_strnarrcmp.c \
			ft_isspace.c \
			ft_rmspaces.c

GNL_FILES = get_next_line.c \
			get_next_line_utils.c

PRF_FILES = ft_printf.c \
			ft_hexlen.c \
			ft_nbrlen.c \
			ft_nbrunsiglen.c \
			ft_printchar_fd.c \
			ft_printhex_fd.c \
			ft_printnbr_fd.c \
			ft_printnbrunsig_fd.c \
			ft_printstr_fd.c

LFT_SRC = $(addprefix $(LFT_SRC_PATH), $(LFT_FILES))
GNL_SRC = $(addprefix $(GNL_SRC_PATH), $(GNL_FILES))
PRF_SRC = $(addprefix $(PRF_SRC_PATH), $(PRF_FILES))

SRCS = $(LFT_SRC) $(GNL_SRC) $(PRF_SRC)
OBJS = $(subst $(SRCS_PATH), $(OBJS_PATH), $(SRCS:.c=.o))
DEPS = $(subst $(SRCS_PATH), $(DEPS_PATH), $(SRCS:.c=.d))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) inc/libft.h Makefile
	@echo "\n"
	@echo "$(YELLOW)	Compiling libft...\n"
	@echo "$(DEF_COLOR)"
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)\n"
	@echo "	===============	"
	@echo "	 libft created	"
	@echo "	===============	"
	@echo "\n"
	@echo "$(DEF_COLOR)"

$(LFT_OBJ_PATH)%.o: $(LFT_SRC_PATH)%.c
	@mkdir -p $(LFT_OBJ_PATH) $(LFT_DEP_PATH)
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@
	@echo "$(GREEN)Creating object $(DEF_COLOR)- $(BLUE)$@"
	@mv $(subst .o,.d, $@) $(LFT_DEP_PATH)

$(GNL_OBJ_PATH)%.o: $(GNL_SRC_PATH)%.c
	@mkdir -p $(GNL_OBJ_PATH) $(GNL_DEP_PATH)
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@
	@echo "$(GREEN)Creating object $(DEF_COLOR)- $(BLUE)$@"
	@mv $(subst .o,.d, $@) $(GNL_DEP_PATH)

$(PRF_OBJ_PATH)%.o: $(PRF_SRC_PATH)%.c
	@mkdir -p $(PRF_OBJ_PATH) $(PRF_DEP_PATH)
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@
	@echo "$(GREEN)Creating object $(DEF_COLOR)- $(BLUE)$@"
	@mv $(subst .o,.d, $@) $(PRF_DEP_PATH)

clean:
	@rm -rf $(OBJS_PATH) $(DEPS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	
-include $(DEPS)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 04:45:01 by dtelnov           #+#    #+#              #
#    Updated: 2023/05/11 06:08:39 by dtelnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROJECT_NAME = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes/
AR = ar rcs
RM = rm -f

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

FTIS = alnum alpha ascii digit print

FTLST = add_back add_front clear delone iter last map new size

FTMEM = bzero calloc memchr memcmp memcpy memmove memset

FTPUT = char_fd endl_fd nbr_fd str_fd

FTSTR = strchr strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr strrchr strtrim longest_array compstr

FTSUB = ft_str/ft_substr ft_str/ft_split

FTTO = tolower toupper

FTCONVERT = ft_convert/ft_atoi ft_convert/ft_itoa

FTEX = gnl/get_next_line printf/ft_printf

FTPRF = nums str utils

FTMATH = abs max min swap_xor

SRCS = $(addsuffix .c, $(addprefix ft_is/ft_is, $(FTIS))) \
	$(addsuffix .c, $(addprefix ft_lst/ft_lst, $(FTLST))) \
	$(addsuffix .c, $(addprefix ft_mem/ft_, $(FTMEM))) \
	$(addsuffix .c, $(addprefix ft_put/ft_put, $(FTPUT))) \
	$(addsuffix .c, $(addprefix ft_str/ft_, $(FTSTR)) $(FTSUB)) \
	$(addsuffix .c, $(addprefix ft_to/ft_, $(FTTO))) \
	$(addsuffix .c, $(addprefix ft_, $(FTEX))) \
	$(addsuffix .c, $(FTCONVERT)) \
	$(addsuffix .c, $(addprefix ft_math/ft_, $(FTMATH))) \
	$(addsuffix .c, $(addprefix ft_printf/ft_printf_, $(FTPRF))) \

OBJS = $(SRCS:.c=.o)

TOTAL = $(words $(SRCS))
COUNT = 0

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n\n[🔘] $(BGREEN)Compiling libft..."
	@$(AR) $(NAME) $^
	@echo "$(NC)"
	@printf "$(BCYAN)[%2d/%2d] 100%%\t$(BWHITE)All files have been compiled ✔️$(NC)\n" $(COUNT) $(TOTAL)
	@echo "[💠] $(BCYAN)$(NAME)\t$(BWHITE)Library created ✔️\n$(NC)"

%.o: %.c
	@printf "[🔄] $(BPURPLE)Generating libft objects... %-33.33s\r$(NC)" $@
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "[🧼] $(BYELLOW)Objects $(YELLOW)files have been cleaned from $(PROJECT_NAME) ✔️$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "[🚮] $(BRED)All $(RED)files have been cleaned ✔️$(NC)"

re: clean all

.PHONY: bonus all clean fclean re

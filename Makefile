NAME = libftprintf.a

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c)
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
OBJ = $(SRC:%.c=%.o)
LIBFT_OBJ = $(LIBFT_SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) #-I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
# LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	@echo "Creating library..."
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Created $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "Removing objects files..."
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@echo "Objects files removed."

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

debug: CFLAGS += -g
debug: fclean all
	@echo "Enable debug mode"

.PHONY: all clean fclean re debug

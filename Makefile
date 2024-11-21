NAME = libftprintf.a

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft

SRC = $(SRC_DIR)/*.c
OBJ = $(SRC:.c=.o)

CC = CC
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean clean
	@$(MAKE) -C $(LIBFT_DIR) re

.PHONY all clean fclean re bonus

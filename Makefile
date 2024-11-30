NAME = libftprintf.a

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
# $(wildcard $(SRC_DIR)/*.c)
SRC = \
	ft_bs_esc.c				\
	ft_countdigits.c		\
	ft_countdigits_hex.c	\
	ft_countdigits_u.c		\
	ft_flags.c				\
	ft_flags_cs.c			\
	ft_flags_di.c			\
	ft_flags_p.c			\
	ft_flags_u.c			\
	ft_flags_x.c			\
	ft_islower.c			\
	ft_isupper.c			\
	ft_itoa_hex.c			\
	ft_itoa_u.c				\
	ft_printf.c				\
	ft_putnchar_fd.c		\
	ft_putnstr_fd.c			\
	ft_strlowercase.c		\
	ft_struppercase.c

LIBFT_SRC = \
	ft_atoi.c				\
	ft_bzero.c				\
	ft_calloc.c				\
	ft_isalnum.c			\
	ft_isalpha.c			\
	ft_isascii.c			\
	ft_isdigit.c			\
	ft_isprint.c			\
	ft_itoa.c				\
	ft_lstadd_back.c		\
	ft_lstadd_front.c		\
	ft_lstclear.c			\
	ft_lstdelone.c			\
	ft_lstiter.c			\
	ft_lstlast.c			\
	ft_lstmap.c				\
	ft_lstnew.c				\
	ft_lstsize.c			\
	ft_memchr.c				\
	ft_memcmp.c				\
	ft_memcpy.c				\
	ft_memmove.c			\
	ft_memset.c				\
	ft_putchar_fd.c			\
	ft_putendl_fd.c			\
	ft_putnbr_fd.c			\
	ft_putstr_fd.c			\
	ft_split.c				\
	ft_strchr.c				\
	ft_strdup.c				\
	ft_striteri.c			\
	ft_strjoin.c			\
	ft_strlcat.c			\
	ft_strlcpy.c			\
	ft_strlen.c				\
	ft_strmapi.c			\
	ft_strncmp.c			\
	ft_strnstr.c			\
	ft_strrchr.c			\
	ft_strtrim.c			\
	ft_substr.c				\
	ft_tolower.c			\
	ft_toupper.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
LIBFT_SRC := $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC))
OBJ = $(SRC:%.c=%.o)
LIBFT_OBJ = $(LIBFT_SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror # -fpic
IFLAGS = -I$(INC_DIR) #-I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
# LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	@echo "Creating library..."
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Created $(NAME)"

bonus: all
	@echo "Enable bonus"

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

# debug: CFLAGS += -g -fpic
# debug: fclean all
# 	@echo "Enable debug mode"

.PHONY: all clean fclean re #debug

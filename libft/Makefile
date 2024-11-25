NAME = libft.a
SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_memchr.c ft_memcmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
  ft_strchr.c	ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRC = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include
# INCL = -I../include
# FPIC = -fPic
AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating $(NAME)..."
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@echo "Created $(NAME)"

bonus: $(OBJ) $(BOBJ)
	@echo "Compiling bonus ..."
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BOBJ)
	@echo "Created $(NAME) with bonus"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@echo "Removing binary $(NAME)..."
	@rm -f $(NAME)

re: fclean all

# debug: clean
# 	@echo "Compiling all bonus with debug"
# 	@$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BOBJ)
# 	@echo "Created $(NAME) with AB"

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BSRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BOBJ)

.PHONY: all bonus clean fclean re debug


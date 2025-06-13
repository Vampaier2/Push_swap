# Makefile for Bonus_ButBetter
NAME      = bonus_butbetter.a

# List all .c files in the directory
SRC_FILES = ft_bzero.c \
            ft_calloc.c \
            ft_lstadd_back.c \
            ft_lstadd_front.c \
            ft_lstclear.c \
            ft_lstiter.c \
            ft_lstlast.c \
            ft_lstnew.c \
            ft_lstsize.c \
            print_list.c

O_FILES   = $(SRC_FILES:.c=.o)

CC        = cc
C_FLAGS   = -Wall -Wextra -Werror
AR        = ar rcs

# Build the static library
all: $(NAME)

$(NAME): $(O_FILES)
	$(AR) $(NAME) $(O_FILES)

# Compile each .c file into .o
%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(O_FILES)

# Clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

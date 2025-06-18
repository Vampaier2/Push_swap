# Makefile for Bonus_ButBetter
NAME      = push_swap.a

# List all .c files in the directory
SRC_FILES = ft_push.c \
            ft_rlst.c \
            ft_sort_int_tab.c \
            get_bit_length.c \
            push_swap.c \

O_FILES   = $(SRC_FILES:.c=.o)

CC        = cc
C_FLAGS   = -Wall -Wextra -Werror
L_FLAGS   = -Lfunc_aux -lfunc_aux
AR        = ar rcs

# Build the static library
all: $(NAME)
	@$(MAKE) clean

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

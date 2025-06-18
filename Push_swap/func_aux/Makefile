# Makefile for Bonus_ButBetter
NAME      = libfunc_aux.a

# List all .c files in the directory
SRC_FILES = ft_atoi.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_lstadd_back.c \
            ft_lstadd_front.c \
            ft_lstnew.c \
            ft_lstsize.c \
            ft_str_isdigit.c \
            int_to_binary.c \
            is_stack_sorted.c \
            print_list.c

O_FILES   = $(SRC_FILES:.c=.o)

CC        = cc
C_FLAGS   = -Wall -Wextra -Werror
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

# Makefile for Bonus_ButBetter
NAME      = push_swap.a

AUX_FILES = func_aux/ft_calloc.c \
            func_aux/ft_conversions.c \
            func_aux/ft_lst_func.c \
            func_aux/is_stack_sorted.c \

PRINT_FILES =	ft_printf/ft_handle_hex.c \
				ft_printf/ft_handle_point.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_putchar_fd.c \
				ft_printf/ft_putdecimal_int.c \
				ft_printf/ft_putnbr_fd.c \
				ft_printf/ft_putstr_fd.c \

SRC_FILES = ft_free_func.c \
            ft_gets.c \
            ft_push_rotate.c \
            ft_parcing.c \
            ft_sorts.c \
			push_swap.c \
            $(AUX_FILES) \
			$(PRINT_FILES) \



O_FILES   = $(SRC_FILES:.c=.o)

CC        = cc
C_FLAGS   = -Wall -Wextra -Werror
L_FLAGS   = -Lfunc_aux -lfunc_aux
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

# Makefile for Bonus_ButBetter
NAME      = push_swap.a

AUX_FILES = func_aux/ft_atoi.c \
            func_aux/ft_bzero.c \
            func_aux/ft_calloc.c \
            func_aux/ft_lstadd_back.c \
            func_aux/ft_lstadd_front.c \
            func_aux/ft_lstnew.c \
            func_aux/ft_lstsize.c \
            func_aux/ft_str_isdigit.c \
            func_aux/int_to_binary.c \
            func_aux/is_stack_sorted.c \
            func_aux/print_list.c \

SRC_FILES = ft_push.c \
            ft_rlst.c \
            ft_sort_int_tab.c \
            get_bit_length.c \
            push_swap.c \
            $(AUX_FILES) \


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

NAME          = push_swap.a
BONUS_DIR     = Bonus_ButBetter
BONUS_LIB     = $(BONUS_DIR)/bonus_butbetter.a

SRC_FILES     = sandbox.c



O_FILES       = $(SRC_FILES:.c=.o)

CC            = cc
C_FLAGS       = -Wall -Wextra -Werror
AR            = ar rcs

# Rule to build the bonus library first
$(BONUS_LIB):
	$(MAKE) -C $(BONUS_DIR)
# Calls Bonus_ButBetter's Makefile

# Main rule: depends on bonus library
all: $(BONUS_LIB) $(NAME)

# Build main library and merge with bonus
$(NAME): $(O_FILES) $(BONUS_LIB)
	$(AR) $(NAME) $(O_FILES)
	$(AR) $(NAME) $(BONUS_LIB)
# Merge bonus objects into push_swap.a

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES)
	$(MAKE) -C $(BONUS_DIR) clean
# Clean bonus objects too

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(BONUS_DIR) fclean
# Clean bonus library too

re: fclean all

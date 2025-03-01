CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -g
RM = rm -f

## Files ##
SRCS = push_swap_main.c push_swap_utils.c push_swap_moves.c push_swap_utils_1.c \

OBJS = $(SRCS:.c=.o)

## Executable ##
NAME = push_swap

## Compilation ##
$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

## Cleaning ##
clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean $(NAME)

## Ensure libft is built ##
libft/libft.a:
	$(MAKE) -C libft all



################################
#####################################################################################


# CC = cc
# CFLAGS = -Wall -Wextra -Werror -I./inc -I./ -g
# LDFLAGS = -L./libft
# RM = rm -f

# ## Files ##

# SRCS = src/push_swap_main.c \
#         src/push_swap_moves.c \
#         src/push_swap_utils.c \

# OBJS = $(SRCS:src/%.c=obj/%.o)

# ## Configuration ##

# NAME = push_swap

# ## Compilation rules ##

# $(NAME): $(OBJS) libft/libft.a
# 	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)obj/%.o: src/%.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

# ## Cleaning rules ##

# clean:
# 	$(RM) $(OBJS)
# 	$(MAKE) -C libft cleanfclean: clean
# 	$(RM) $(OBJS) $(NAME)
# 	$(MAKE) -C libft fcleanre: fclean $(NAME)

# ## Libraries ##

# libft/libft.a:
# 	$(MAKE) -C libft all

# printf/printf.:
# 	$(MAKE) -C printf all

##################################


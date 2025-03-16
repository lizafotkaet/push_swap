CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -g
RM = rm -f

## Files ##
SRCS = main.c push_swap_utils.c push_swap_utils_1.c \
		push_swap_dll_fts.c push_swap_moves.c push_swap_sort.c \
		sort_utils.c push_swap_sort_1.c \

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


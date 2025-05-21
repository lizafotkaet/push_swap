CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -g 
RM = rm -f

SRCS = main.c dll_fts.c moves.c moves_1.c \
		moves_2.c sort.c sort_1.c \
		utils.c utils_1.c sort_three.c \

# Added OBJDIR variable for object files directory
OBJDIR = obj
# Updated OBJS variable to include the directory
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = push_swap

## Compilation ##
$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) -Llibft -lft

# Updated compilation rule to place .o files in the OBJDIR
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

## Cleaning ##
clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR) # Remove the object files directory
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean $(NAME)

## Ensure libft is built ##
libft/libft.a:
	$(MAKE) -C libft all


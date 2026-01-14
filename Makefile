NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I.

OBJDIR		= obj

SRCS		= main.c \
			  parsing.c \
			  push_swap.c \
			  sort_big.c \
			  sort_small.c \
			  stack_nodes.c \
			  indexer.c \
			  algo_lis.c \
			  algo_lis2.c \
			  algo_cost.c \
			  algo_cost2.c \
			  algo_rotate.c \
			  algo_insert.c \
			  ops_primitives.c \
			  ops_swap_push.c \
			  ops_rotates.c \
			  ops_rev_rotates.c \
			  utils.c

OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c push_swap.h Makefile
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
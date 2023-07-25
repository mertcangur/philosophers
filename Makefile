NAME = philo

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	=	main.c \
			init.c \
			util.c \
			start.c \
			thread.c

OBJS	= $(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@printf "\e[32m (＾▽＾) \e[0m\n";

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS)
			@printf "\e[33m(￣▽￣) \e[0m\n"

fclean:		clean
			@$(RM) $(NAME)
			@printf "\e[31m( ￣＾￣) \e[0m\n"

re:			fclean all

.PHONY:	all clean fclean re



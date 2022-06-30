NAME			=	containers
CC				=	c++
CPPFLAGS		=	-std=c++98
# CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	main.cpp
HSRCS			=	vector/vector.hpp

all				: $(NAME)

$(NAME)			: $(SRCS) $(HSRCS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean			:

fclean			: clean
	@/bin/rm -f $(NAME)

re				: fclean all

test			: re
	@./$(NAME)

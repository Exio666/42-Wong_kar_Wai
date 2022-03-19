OBJS_PATH =	objs/

SRCS_PATH =	srcs/

SRCS_LIBFT	= 	$(addprefix $(PATH_LIBFT),	\
				game/game.c					\
				test.c						\
				display/render.c)

SRCS = $(SRCS_GNL) $(SRCS_LIBFT) $(SRCS_PFT)

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

DEPS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.d))

INCS = -I includes -I libft/includes

RM = rm -rf

NAME	= 2048

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

ALLLIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(ALLLIB)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) -l ncurses -o $(NAME) $(INCS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@ $(INCS)
	
clean:
	$(RM) $(OBJS_PATH)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

libft/libft.a :
	$(MAKE) -C libft all

re: fclean all 

-include $(DEPS)

.PHONY: all clean fclean re
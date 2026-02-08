NAME        = ptyman
CC          = gcc
CFLAGS      = 
SRCS        = main.c ptyctrl.c winsize.c playerutils.c screenutlis.c move.c
OBJS        = $(addprefix $(BUILD), $(SRCS:.c=.o))
RM          = rm -rf
BUILD       = build/

all: $(BUILD) $(NAME)

play:
	./$(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BUILD)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
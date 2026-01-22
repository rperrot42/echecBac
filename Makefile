DIR_OBJS = .objs

SRC = main.c \
        fonction.c

CC = gcc -g3

FLAGS =  -I/opt/homebrew/include/SDL2 -D_THREAD_SAFE -L/opt/homebrew/lib -lSDL2 -g3

OBJS = $(addprefix $(DIR_OBJS)/, $(SRC:.c=.o))

INCLUDE = sdl.h

NAME = echec

$(DIR_OBJS)/%.o: %.c Makefile $(INCLUDE) | $(DIR_OBJS)
	$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all%   
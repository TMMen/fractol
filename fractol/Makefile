NAME 		= fractol

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f

MLX			= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

INC			= -I ./minilibx-linux/ 

SOURCES 	= fractol_events.c fractol_initialize.c \
			fractol_main.c fractol_math.c \
			fractol_render.c fractol_strings.c
OBJECTS		= fractol_events.o fractol_initialize.o \
			fractol_main.o fractol_math.o \
			fractol_render.o fractol_strings.o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(NAME) $(OBJECTS)

fclean:
	$(RM) $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all re clean fclean
NAME = fractol
LIBMLX_PATH = ./MLX42
LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -lm
HEADERS = -I ./include -I $(LIBMLX_PATH)/include/ -I "/Users/stuna/.brew/opt/glfw/include"
LIBS = $(LIBMLX) -L/Users/stuna/.brew/lib/ -ldl -lglfw -pthread -lm
SRCS = maan.c hooks.c fractals.c errors.c utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

$(NAME): $(LIBMLX) $(SRCS)
	cc $(CFLAGS) $(HEADERS) $(SRCS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX_PATH)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx

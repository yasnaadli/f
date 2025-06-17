CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = ./minilibx
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lm -lXext
HEADER = -Iheader -I$(MLX_PATH)

NAME = fractol

SRCS = handle_events.c fractal_events.c fractal_init.c fractal_render.c \
	main.c fractal_logic.c fractal_utils.c ft_utils.c  ft_atoi_utils.c
OBJS = $(SRCS:.c=.o)

COLOR_RESET = \033[0m
COLOR_BLUE = \033[0;34m
RM = rm -rf

.PHONY: all clean fclean re install uninstall

all: $(NAME)

$(NAME): $(OBJS) | $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(COLOR_BLUE)$(NAME) ready to paint fractals!$(COLOR_RESET)"

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		$(MAKE) install; \
	fi
	@$(MAKE) -C $(MLX_PATH)

install:
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	@$(MAKE) -C $(MLX_PATH)
	@echo "🔮Minilibx installed!🔮"

clean:
	@$(RM) $(OBJS)
	@echo ".o files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "Canvas is clean now!"

uninstall: fclean
	@$(RM) $(MLX_PATH)
	@echo "Minilibx uninstalled!"

re: fclean all
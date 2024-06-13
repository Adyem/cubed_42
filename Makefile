
NAME		= so_long
DEBUG_NAME	= so_long_debug

SRC		= so_long.c \
		  read_file.c \
		  free_memory.c \
		  debug.c \
		  error_map.c \
		  check_map.c \
		  check_route.c \
		  open_window.c \
		  error_mlx.c \
		  init_info.c \
		  run_game.c \
		  handle_keypress.c \
		  utils.c

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
HEADER	= so_long.h

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libftprintf.a

# New minilibx setup
MINILIBX_TGZ = minilibx-linux.tgz
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd

LDFLAGS	= -L$(LIBFT_DIR) -lftprintf $(MINILIBX_FLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

all: $(LIBFT) $(NAME)

debug: $(LIBFT) debug_build

debug_build: CFLAGS += -DDEBUG=1
debug_build: $(DEBUG_NAME)

$(DEBUG_NAME): $(MINILIBX_LIB) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(DEBUG_NAME) $(LDFLAGS)

$(NAME): $(MINILIBX_LIB) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# New rule for handling minilibx
$(MINILIBX_LIB):
	tar -xzf $(MINILIBX_TGZ)
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME) $(DEBUG_NAME)

re: fclean all

both: all debug

redebug: fclean debug

.PHONY: all clean fclean re debug redebug both


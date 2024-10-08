NAME		= cub3D
DEBUG_NAME	= cub3D_debug

SRC		= main.c \
		  free_memory.c \
		  utils01.c \
		  open_map.c \
		  parser01.c \
		  check_map.c \
		  check_value.c \
		  error_managment.c \
		  find_entrance.c \
		  flooder.c \
		  init_xpm.c \
		  mlxloop.c \
		  movement.c \
		  multiple_checks.c \
		  raycasting.c \
		  ray_draw.c \
		  start_mlx.c \
		  color_string.c

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJS_DEBUG	= $(addprefix $(OBJ_DIR)/,$(SRC:.c=_debug.o))

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
DEBUG_FLAGS = -Wall -Werror -Wextra -g -DDEBUG=1
HEADER	= cubed.h

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libftprintf.a

MINILIBX_TGZ = minilibx-linux.tgz
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd

LDFLAGS	= -L$(LIBFT_DIR) -lftprintf $(MINILIBX_FLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(OBJ_DIR)/%_debug.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(DEBUG_FLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

all: $(LIBFT) $(NAME)

debug: $(LIBFT) $(DEBUG_NAME)

$(DEBUG_NAME): $(MINILIBX_LIB) $(OBJS_DEBUG) $(LIBFT)
	$(CC) $(DEBUG_FLAGS) $(OBJS_DEBUG) -o $(DEBUG_NAME) $(LDFLAGS)

$(NAME): $(MINILIBX_LIB) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	tar -xzf $(MINILIBX_TGZ)
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME) $(DEBUG_NAME)

hclean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

both: all debug

redebug: fclean debug

.PHONY: all clean fclean re debug redebug both hclean

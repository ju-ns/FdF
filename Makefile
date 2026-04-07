NAME		= fdf

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iinclude -Ilibft -Iminilibx-linux

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX		= $(MLX_DIR)/libmlx.a

SRC_DIR		= src
OBJ_DIR		= obj

SRC	= \
	  $(SRC_DIR)/main.c	\
	  $(SRC_DIR)/graphics/screen_setup.c	\
	  $(SRC_DIR)/graphics/image_setup.c	\
	  $(SRC_DIR)/hooks/hooks.c	\
	  $(SRC_DIR)/matrix/tad_matrix.c	\
	  $(SRC_DIR)/parse/parse_color.c	\
	  $(SRC_DIR)/parse/parse_file.c	\
	  $(SRC_DIR)/parse/parse_size.c	\
	  $(SRC_DIR)/parse/parse_token.c	\
	  $(SRC_DIR)/parse/parse_utils.c	\
	  $(SRC_DIR)/parse/validations.c	\
	  $(SRC_DIR)/projection/iso_projection.c	\
	  $(SRC_DIR)/render/color.c	\
	  $(SRC_DIR)/render/map.c	\
	  $(SRC_DIR)/render/pixel.c	\
	  $(SRC_DIR)/render/render_utils.c	\
	  $(SRC_DIR)/render/render.c

OBJ	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@echo "Building libft ..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "Building mlx ..."
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) Compiled with success"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re





	


NAME = cub3D

SOURCES = \
cub.c \
cub_common/cub_destroy.c \
cub_init/cub_init.c \
cub_init/cub_map_img_init.c \
cub_loop/cub_draw_line.c \
cub_loop/cub_img_clear.c \
cub_loop/cub_img_copy.c \
cub_loop/cub_loop.c \
cub_loop/cub_raycast.c \
cub_loop_init/cub_loop_init.c \
cub_init/cub_new_img.c

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
SOURCES_DIR = sources
INCLUDE_DIR = include
BUILD_DIR = build

ifeq ($(shell uname), Darwin)
X11_DIR = /usr/X11/lib
else
X11_DIR = /usr/lib
endif

CC = cc
CFLAGS = -I$(INCLUDE_DIR) -I$(MLX_DIR) -MD -Wall -Wextra -Werror -g
LFLAGS = -L$(X11_DIR) -lX11 -lXext -lm
RM = rm -rf
MKDIR = mkdir -p

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
OBJECTS = $(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES = $(OBJECTS:.o=.d)

all: $(NAME)

-include $(DEPENDENCIES)

$(LIBFT): FORCE
	$(MAKE) -C	$(LIBFT_DIR)

$(MLX): FORCE
	$(MAKE) -C	$(MLX_DIR)

$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	$(MAKE) -C	$(LIBFT_DIR) $@
	$(MAKE) -C	$(MLX_DIR) $@
	$(RM) $(BUILD_DIR)

fclean:
	$(MAKE) -C	$(LIBFT_DIR) $@
	$(MAKE) -C	$(MLX_DIR) clean
	$(RM) $(BUILD_DIR) $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE

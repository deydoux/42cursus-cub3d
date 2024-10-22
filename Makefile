NAME = cub3D

SOURCES = \
common/destroy.c \
common/draw_map_square.c \
common/read_img.c \
cub.c \
init_loop/focus_in.c \
init_loop/focus_out.c \
init_loop/init_loop.c \
init_loop/key_press.c \
init_loop/key_release.c \
init_loop/quit.c \
init/fill_img.c \
init/init_img.c \
init/init_map_img.c \
init/init.c \
init/new_img.c \
init/open_img.c \
loop/clear_frame.c \
loop/copy_img.c \
loop/copy_minimap.c \
loop/draw_wall.c \
loop/loop.c \
loop/mouse_rot.c \
loop/move.c \
loop/pol_vec.c \
loop/raycasts.c \
loop/render_minimap.c \
loop/render_ray.c \
parse/error_and_free.c \
parse/colors.c \
parse/doable.c \
parse/initialise.c \
parse/mapping.c \
parse/textures.c \
parse/tools.c \
parse/parse.c \
parse/safe_fctn.c \

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

run: $(NAME)
	./$^

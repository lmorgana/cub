CC = gcc

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror

HEADERS = header.h libft/libft.h src/get_next_line/get_next_line.h src/map_validator/map_validator.h\
			src/print_map/print_map.h

SRC = 	main.c src/init.c src/utils.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
		src/parser/parser.c src/parser/utils.c src/parser/ft_get_data.c src/parser/ft_get_map.c src/parser/ft_check_data.c \
		src/parser/ft_is_texture.c src/map_validator/ft_check_map.c src/map_validator/ft_is_surround.c \
		src/map_validator/ft_splist.c src/print_map/ft_print_map.c src/parser/validation_texture.c src/parser/validation_data.c \
		src/moves/ft_hooks.c src/moves/turn.c src/print_map/print_map_utils.c src/print_map/ft_print_map2.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

LIBFT_LIB = libft/libft.a

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C libft bonus

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lmx
clean:
	$(MAKE) -C libft clean
	-rm -f $(OBJECTS)

fclean:
	$(MAKE) -C libft fclean
	-rm -f $(OBJECTS)
	-rm -f $(NAME)

re: fclean all
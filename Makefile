SRCS = ./Get_next_line/get_next_line.c ./Get_next_line/get_next_line_utils.c init.c verif_map.c main.c ft_key.c clear.c

SRCSBONUS = 

OBJS = $(SRCS:%.c=%.o)

OBJSBONUS = $(SRCSBONUS:%.c=%.o)

CC   = gcc -g3 -Wall -Wextra -Werror

NAME = so_long

HEAD = so_long.h 

HEADBONUS = 

all: $(NAME)

bonus:	$(OBJSBONUS) $(HEADBONUS)
	make -C ./Libft
	$(CC) $(SRCSBONUS) -Iincludes ./Libft/libft.a -o $(NAME)

clean:
	make -C ./Libft clean
	rm -f $(OBJS)
	rm -f $(OBJSBONUS)

fclean: clean
	make -C ./Libft fclean
	rm -f $(NAME)
	rm -f $(NAMEBONUS)

re: fclean
	make all

$(NAME): $(OBJS) $(HEAD)
	make -C ./minilibx-linux
	make -C ./Libft
	$(CC) $(SRCS) -Iincludes ./Libft/libft.a -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $@

$(NAMEBONUS):	

.PHONY: all bonus clean fclean re

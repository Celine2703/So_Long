SRCS = ./Get_next_line/get_next_line.c ./Get_next_line/get_next_line_utils.c init.c verif_map.c main.c ft_key.c clear.c ft_cpt.c

SRCSBONUS = ./Get_next_line/get_next_line.c ./Get_next_line/get_next_line_utils.c ./BONUS/init.c ./BONUS/verif_map.c ./BONUS/main.c ./BONUS/ft_key.c ./BONUS/clear.c ./BONUS/ft_cpt.c ./BONUS/swap.c ./BONUS/display.c ./BONUS/patrouille.c

OBJS = $(SRCS:%.c=%.o)

OBJSBONUS = $(SRCSBONUS:%.c=%.o)

CC   = gcc -g3 -Wall -Wextra -Werror

NAME = so_long

NAMEBONUS = so_long_bonus

HEAD = so_long.h

HEADBONUS = ./BONUS/so_long_bonus.h

all: $(NAME)

bonus:	$(NAMEBONUS)

$(NAMEBONUS): $(OBJSBONUS) $(HEADBONUS)
	make -C ./minilibx-linux
	make -C ./Libft
	$(CC) $(SRCSBONUS) -Iincludes ./Libft/libft.a -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $@

clean:
	make -C ./Libft clean
	rm -f $(OBJS)
	rm -f $(OBJSBONUS)

fclean: clean
	rm -f ./Libft/libft.a
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

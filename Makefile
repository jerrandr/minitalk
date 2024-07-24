CC = cc -Wall -Wextra -Werror -g
NAME_SERVER = server
NAME_CLIENT = client
SRC_SERVER = server.c libft_utils/ft_atoi.c libft_utils/ft_strdup.c libft_utils/ft_strlen.c libft_utils/ft_putnbr.c 
SRC_CLIENT = client.c libft_utils/ft_atoi.c libft_utils/ft_strdup.c libft_utils/ft_strlen.c libft_utils/ft_putnbr.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) -o $@

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean all re fclean

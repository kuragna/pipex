NAME	  	=	pipex
CC		  	=	gcc
CFLAGS	  	=	-Wall -Werror -Wextra 
RM		  	=	rm -f
SRC		  	= 	cmds.c get_paths.c get_cmd_path.c get_freed.c error.c main.c check_sh.c
OBJ			= 	$(addprefix src/, $(SRC:.c=.o))
INC_LIB		= 	./libft/libft.a


all: $(INC_LIB) $(NAME) 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(INC_LIB):
	make all -C ./libft/

$(NAME): $(OBJ) 
	$(CC) -o $@ $(CFLAGS) -L. $(INC_LIB) $(OBJ)
	
clean: 
	make clean -C ./libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re INC_LIB


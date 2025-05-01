NAME_SERV= server
SERVER_FILE= server.c
SERVER_OBJ= $(SERVER_FILE:.c=.o)

NAME_CLIENT= client
CLIENT_FILE= client.c
CLIENT_OBJ= $(CLIENT_FILE:.c=.o)

UTILS_FILE= utils.c
UTILS_OBJ= $(UTILS_FILE:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra



all: $(NAME_SERV) $(NAME_CLIENT)

$(NAME_SERV): $(SERVER_OBJ) $(UTILS_OBJ)
	@echo "Preparing $(NAME_SERV)..."
	$(CC) $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(NAME_SERV)
	@echo "$(NAME_SERV) created!"
$(NAME_CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "Preparing $(NAME_CLIENT)..."
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(NAME_CLIENT)
	@echo "$(NAME_SERV) created!"
clean:
	@echo "Removing objs..."
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "Done!"

fclean: clean
	@echo "Removing files..."
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "Done!"

re: fclean all

.PHONY:		all clean fclean re

 

NAME = proxy_server
FLGS = g++ -pthread
OBJ_DIR = obj/
SRC_DIR = src/

SRC_FILES = $(addprefix $(SRC_DIR), Client Server proxy_server)
SRC_O = $(addprefix $(OBJ_DIR), $(SRC_FILES:=.o))

.PHONY = all clean fclean re

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)

$(NAME): $(SRC_O)
	$(FLGS) $(SRC_O) -o $(NAME)
	@echo "\033[32m[+] Make completed!\033[0m"

$(SRC_O): $(OBJ_DIR)%.o: %.cpp
	$(FLGS)  -c $< -o $@

clean:
	@rm -rf obj
fclean: clean
	@rm -f $(NAME)
re: fclean all
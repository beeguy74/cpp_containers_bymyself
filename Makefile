NAME	=		test	

FILES	=		test vector_tests stack_test map_tests set_tests
HEADERS =		stack

CXX		=		c++

SRC_DIR	=		src/
OBJ_DIR	=		obj/
INCLUDE_DIR =	include/

FLAGS	= -Wall -Wextra -Werror -I $(INCLUDE_DIR) -g -std=c++98

SRCS 	= $(patsubst %, $(SRC_DIR)%.cpp, $(FILES))
HDRS	= $(patsubst %, $(INCLUDE_DIR)%.hpp, $(HEADERS))
OBJS 	= $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) -o $(NAME) $(OBJS) $(FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HDRS)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME	=		test.out
SCHOOL_NAME =	school_test.out

FILES	=		test vector_tests stack_test map_tests set_tests
HEADERS =		stack

CXX		=		c++

SRC_DIR	=		src/
OBJ_DIR	=		obj/
INCLUDE_DIR =	include/

FLAGS	= -Wall -Wextra -Werror -I $(INCLUDE_DIR) -std=c++98

SRCS 	= $(patsubst %, $(SRC_DIR)%.cpp, $(FILES))
HDRS	= $(patsubst %, $(INCLUDE_DIR)%.hpp, $(HEADERS))
OBJS 	= $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

SCHOOL_SRC = $(SRC_DIR)school_main.cpp
SCHOOL_OBJ = $(OBJ_DIR)school_main.o

all: $(NAME) $(SCHOOL_NAME)

$(SCHOOL_NAME):  $(SCHOOL_OBJ) $(HDRS)
	mkdir -p $(OBJ_DIR)
	$(CXX) -o $(SCHOOL_NAME) $(SCHOOL_OBJ) $(FLAGS)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) -o $(NAME) $(OBJS) $(FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HDRS)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f ./$(NAME) $(SCHOOL_NAME)

re: fclean all

.PHONY: all clean fclean re
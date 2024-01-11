CC = g++
NAME = ruins
SRC = $(wildcard *.cpp)
TEST_SRC = $(wildcard tests/*.cpp)
OBJ = $(SRC:.cpp=.o)
OBJ_TEST = $(TEST_SRC:.cpp=.o)
RM = rm
CFLAGS = -std=c++17

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

all: $(NAME)

test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	$(RM) -f *~ $(NAME)

oclean:
	$(RM) -f $(OBJ) $(OBJ_TEST)

fclean: clean oclean

re: clean all

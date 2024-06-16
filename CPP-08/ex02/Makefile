CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

EXEC = exec

SRCS = \
		main.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(EXEC)

re :		fclean all

.PHONY : 	all clean fclean re
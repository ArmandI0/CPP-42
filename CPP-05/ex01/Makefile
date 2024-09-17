CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

EXEC = exec

SRCS = \
		main.cpp \
		Bureaucrat.cpp \
		Form.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXEC)
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

EXEC = exec

SRCS = \
		AMateria.cpp \
		Cure.cpp \
		Ice.cpp \
		main.cpp \
		MateriaSource.cpp \
		Character.cpp \
		Floor.cpp \


OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXEC)
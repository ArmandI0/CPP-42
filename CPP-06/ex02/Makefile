# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aranger <aranger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 16:48:32 by aranger           #+#    #+#              #
#    Updated: 2024/06/08 14:08:09 by aranger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

EXEC = exec

SRCS = \
		main.cpp \
		Base.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXEC)
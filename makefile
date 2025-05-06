
PROG := mc
SRC := main.cpp circle.cpp rectangle.cpp polygon.cpp
# SRC := *.cpp

OBJS := $(SRC:.cpp=.o)

CC := g++
CXXFLAGS := -Wextra -I. 
LIBS := -lboost_system -lrt  

DEBUG_FLAGS = -g -O0 -DDEBUG
RELEASE_FLAGS = -O3 -DNDEBUG

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: all

release: CXXFLAGS += $(RELEASE_FLAGS)
release: all

all:  root 
	$(CC) $(CXXFLAGS) $(OBJS) $(LIBS) -o $(PROG)

root: $(OBJS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(PROG)

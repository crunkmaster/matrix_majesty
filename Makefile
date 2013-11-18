CXXFLAGS = -std=c++0x
CC = g++
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
HEADERS = $(wildcard *.hpp)

gen_matrix: $(OBJS)

-include .depend

.depend: $(SRCS) $(HEADERS)
	$(CC) $(CXXFLAGS) -MM $(SRCS) > .depend

clean:
	-rm -f *.ii
	-rm -f *.i
	-rm -f *.s
	-rm -f *.o
	-rm -f *.h.gch
	-rm -f *#
	-rm -f *~

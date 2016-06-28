OBJS=Main.o
CPPFLAGS=$(INCLUDE) -std=c++14 -MD

all : $(OBJS)
	$(CXX) -o Main $(LDFLAGS) $(OBJS)

clean :
	$(RM) *.o
	$(RM) Main
	$(RM) *.d

-include *.d


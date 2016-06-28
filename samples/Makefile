INCLUDE=-I../
CPPFLAGS=$(INCLUDE) -std=c++14 -MD

fraction :
	$(CXX) -o Fraction $(LDFLAGS) $(CPPFLAGS) Fraction.cpp

clean :
	$(RM) *.o
	$(RM) Fraction
	$(RM) *.d

-include *.d


main: main.o cppnum_caracs.o
	g++ $(CFLAGS) -o main main.o cppnum_caracs.o
	main.o: main.c cppnum_caracs.hpp
	gcc $(CFLAGS) -c main.c
	cppnum_caracs.o: cppnum_caracs.cpp cppnum_caracs.hpp
	g++ $(CFLAGS) -c cppnum_caracs.cpp
	clean:
	rm -f *.o cppnum_caracs

questao07: questao07.o bib_arqs.o
	gcc $(CFLAGS) -o questao07 questao07.o bib_arqs.o
questao07.o: questao07.c bib_arqs.hpp
	gcc $(CFLAGS) -c questao07.c
bib_arqs.o: bib_arqs.c bib_arqs.hpp
	g++ $(CFLAGS) -c bib_arqs.c

questao06: questao06.o bib_arqs.o
	gcc $(CFLAGS) -o questao06 questao06.o bib_arqs.o
questao06.o: questao06.c bib_arqs.hpp
	gcc $(CFLAGS) -c questao06.c

clean:
	rm -f *.o questao07 questao06
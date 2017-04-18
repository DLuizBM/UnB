questao03: questao03.o crescente.o decrescente.o
	gcc $(CFLAGS) -o questao03 questao03.o crescente.o decrescente.o
questao03.o: questao03.c crescente.h decrescente.h
	gcc $(CFLAGS) -c questao03.c
crescente.o: crescente.c crescente.h
	gcc $(CFLAGS) -c crescente.c
decrescente.o: decrescente.c decrescente.h
	gcc $(CFLAGS) -c decrescente.c

clean:
	rm -f *.o questao03
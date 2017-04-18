questao1: questao1.o calc.o ler_entradas.o 
	gcc $(CFLAGS) -o questao1 questao1.o calc.o ler_entradas.o -lm
questao1.o: questao1.c calc.h ler_entradas.h pontos.h
	gcc $(CFLAGS) -c questao1.c -lm
calc.o: calc.c calc.h 
	gcc $(CFLAGS) -c calc.c -lm
ler_entradas.o: ler_entradas.c ler_entradas.h
	gcc $(CFLAGS) -c ler_entradas.c
clean:
	rm -f *.o questao1

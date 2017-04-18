#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>


int main(){
/*
	clock_t start, stop;
	long int i = 0;
	start = clock();
	for(i = 0; i < 9999; i++)	{
		i++;
	}
	stop = clock();
	printf("%ld\n", start);
	printf("%ld\n", stop);
	printf("%lf\n", ((double)(stop - start)/CLOCKS_PER_SEC));

*/

	clock_t start, stop;
	int i = 0;

	int n, total = 0;

	start = clock();
	for(i = 0; i < 5; i++)	{
		//i++;
		//total = 0;

		srand((unsigned) time(NULL));
		n = rand() % 3;
		printf("%d\n", n);
		sleep((int)n);
		total += n;
		//stop += 
	}
	stop = clock();
	printf("%ld\n", start);
	printf("%ld\n", stop);
	printf("TOTAL: %d\n", total);
	printf("%.3lf\n", ((double)(stop - start)/CLOCKS_PER_SEC));

}

#include <stdio.h>
int num_caracs(char *string){
    int i = 0;
    while(string[i] != '\0')
        i++;
    return i;

}

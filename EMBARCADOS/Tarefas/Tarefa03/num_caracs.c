int num_caracs(char *string){
#include <stdio.h>
    int i = 0;
    while(string[i] != '\0')
        i++;
    return i;

}

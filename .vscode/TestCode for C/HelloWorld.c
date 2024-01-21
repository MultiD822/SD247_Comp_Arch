#include <stdio.h>
#include <stdlib.h>

int main(){
    
    unsigned char x = 0x66, y = 0x39;
    
    printf("x & y = %u\n", x & y);
    printf("x | y = %u\n", x | y);
    printf("~x | ~y = %u\n", ~x | ~y);
    printf("x & !y = %u\n", x & !y);
    printf("x && y = %u\n", x && y);
    printf("x || y = %u\n", x || y);
    printf("!x || !y = %u\n", !x || !y);
    printf("x && ~y = %u\n", x && ~y);
    
    return 0;
}
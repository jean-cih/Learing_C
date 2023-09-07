#include <stdio.h>

void function(int a, int b);
   

int main(){

int a, b;
char x, y;
scanf("%d%c%d%c", &a, &x, &b, &y);

if((a + 0 == a) && (b + 0 == b)){
    if((x == ' ') && (y == '\n'))
        function(a,b);
    else
        printf("n/a\n");
}   
else
    printf("n/a\n");
}

void function(int a, int b){
    if(a > b)
        printf("%d\n", a);
    else if(a < b)
        printf("%d\n", b);  
    else 
        printf("n/a\n");
}
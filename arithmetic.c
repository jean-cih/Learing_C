#include <stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

    
int main(){  
    
    int a , b;
    char x , y;
    scanf("%d%c%d%c", &a, &x, &b, &y);

    if((x == ' ') && (y == '\n')){
  
        if(b == 0)
        printf("%d %d %d n/a\n", sum(a, b), sub(a, b), mul(a, b));
   
        else
         printf("%d %d %d %d\n", sum(a, b), sub(a, b), mul(a, b), div(a, b));
    }
    else 
        printf("n/a\n");
    return 0;
    
}

int sum(int a, int b){
    return (a+b);
}

int sub(int a, int b){
    return ( a - b);
}

int mul(int a, int b){
    return ( a * b);
}

int div(int a, int b){
    return ( a / b);
}
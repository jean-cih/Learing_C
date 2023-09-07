#include <stdio.h>
#include <math.h> 


int main(){

    float x, y;
    char a;
    scanf("%f%c", &x, &a);
    if((x + 0 == x)){
        if((a == '\n')){
            y = (7*powl(10,-3)) * powl(x,4) + ((22.8 * powl(x,1/3)- 1000) * x + 3) / (powl(x,2) / 2) - x * powl((10 + x),(2*powl(x,-1))) - 1.01;
            printf("%.1f\n", y);
         }
        else
            printf("n/a\n");
    }

    
    else
        printf("n/a\n");
}
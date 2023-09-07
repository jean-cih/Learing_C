#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){

    char arr[21][51];
    int i;
    int x = 25, y = 10;
    char key;
    int ox, oy;
    int u = 12, v = 14;

    srand(time(NULL));

    do{
        sprintf(arr[0], "##################################################");

        for(i = 1; i < 19; i++)
            sprintf(arr[i], "#                                                #");
        
        sprintf(arr[19], "##################################################");
        sprintf(arr[20], "                  SCORE = 0                       ");
        arr[y][x] = '@';
        arr[u][v] = '*';
        system("cls");
        for(i = 0; i < 21; i++)
            printf("%s\n", arr[i]);
        key = getchar();
        ox = x;
        oy = y;

        if(key == 'w')
            y--;
        if(key == 's')
            y++;
        if(key == 'a')
            x--;
        if(key == 'd')
            x++;

        if(arr[y][x] == '#'){
            x = ox;
            y = oy;
        }
        if((u == y) && (v == x)){
            v = rand() * 1.0 / RAND_MAX * 49 + 1;
            u = rand() * 1.0 / RAND_MAX * 18 + 1;
        }
       


        }
    while(key != 'r');

    return(0);
}         
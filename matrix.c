#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void usleep(int x);


int main(){

    int a;
    char array[42] = {'A','B','C','D','E','F','G','H','I','J','K','L','$','$','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9',' ',' ',' ','?','!','$','#'};
    while(1){

        usleep(100000);
        for(int i = 0; i < 2000; i++){
            a = rand() % 42;
            printf("\033[1;32;40m    %c  ", array[a]);

        /*
            0m = default
            1m = intensity
            2m = dim
            4m = underline
            5m = flashing
            7m = reversion
            22m = normal brightness
            24m = undo underlining
            25m = undo flashing 
            27m = undo reversion
        TEXT COLOR (30m - 39m)
            30m = black
            31m = red
            32m = green
            33m = orange
            34m = blue
            35m = pink
            36m = azure
            37m - 39m = white
        BACKGROUND COLOR (40m - 47m)
            40m = black
            41m = red
            42m = green
            43m = orange
            44m = blue
            45m = pink
            46m = azure
            47m = white
        */
        }
        printf("\n");
    }
    return 0;
}
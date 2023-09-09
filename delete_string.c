#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rewrite(char *array, int flag, int p, int r);




int main(){

    char *array = NULL;
    array = (char*)malloc(sizeof(char));
    char tap = 0;
    int p = 0;

    while(tap != '\n'){
        tap = getchar();
        p++;
        array = (char*)realloc(array, p * sizeof(char));
        array[p - 1] = tap;
    }

    char *bless = NULL;
    bless = (char*)malloc(sizeof(char));
    char press = 0;
    int r = 0;

    while(press != '\n'){
        press = getchar();
        r++;
        bless = (char*)realloc(bless, r * sizeof(char));
        bless[r - 1] = press;
    }

    int type = 1;
    int flag = 0;

    for(int i = 0; i < p - 1 ; i++){

        flag++;
        if(array[i] == bless[0]){
            for(int j = 0; j < r - 2; j++){
                if(array[j + flag] == bless[j + 1]){
                    type++;
                    if(type == r - 1){
                        rewrite(array, flag, p, r);
                    }
                }
                else{
                    type = 1;
                    break;
                }
            }
        }
    }

    free(array);
    free(bless);

    return 0;
}

int rewrite(char *array, int flag, int p, int r){

    char str1[flag - 1];
    for(int i = 0; i < flag - 1; i ++){
        str1[i] = array[i];
    }

    char str2[p - flag  - r + 1];
    for(int i = 0; i < p - flag - r + 1; i++){
        str2[i] = array[i + flag + r - 2];
    }

    char endstr[p - r];

    for(int i = 0; i < p - r; i++){
        if(i < flag - 1)
            endstr[i] = str1[i];  
        else
            endstr[i] = str2[i - flag + 1];
    } 

    for(int i = 0; i < p - r; i++)
        printf("%c", endstr[i]);

    return 0;
}
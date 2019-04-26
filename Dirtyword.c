#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Structure.h"
extern data database[100];
extern char k[200];

int getrand(){
    int a;
    srand((unsigned)time(NULL));
    a = rand();
    return a;
}

int dirtyw(){
    int l=0;
    FILE *fp;
    int i,j;
    FILE *fps = fopen("dirty words.txt", "r");
    char c = fgetc(fps);
    while ( c != EOF )
    {
        c = fgetc(fps);
        if(c == '\n')
        {   l++; }
    }
    fclose(fps);
    char d[l][100];
    fp = fopen("dirty words.txt", "r");
    for(i=0;i<l;i++){
        for(j=0;;j++){
            fscanf(fp,"%c",&d[i][j]);
            if(d[i][j]=='\n')
            {
                d[i][j]=' ';
                j=j+1;
                for (j=j;j<100;j++)
                {
                    d[i][j] = '\0';
                }
                break;
            }
        }
    }
    for(i=0;i<l;i++){
        if(  (strstr(k,d[i])!=NULL)){
            return 1;
        }
    }
    return 0;
}

int cheakdirty(char name[]){
    int l=0;
    FILE *fp;
    int i,j;
    FILE *fps = fopen("dirty words.txt", "r");
    char c = fgetc(fps);
    while ( c != EOF )
    {
        c = fgetc(fps);
        if(c == '\n')
        {   l++; }
    }
    fclose(fps);
    char d[l][100];
    fp = fopen("dirty words.txt", "r");
    for(i=0;i<l;i++){
        for(j=0;;j++){
            fscanf(fp,"%c",&d[i][j]);
            if(d[i][j]=='\n'){
                d[i][j]='\0';
                break;
            }
        }
    }
    for(i=0;i<l;i++){
        if(  (strstr(name,d[i])!=NULL)){
            return 1;
        }
    }
    return 0;
}

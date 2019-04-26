#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"
extern data database[100];
extern char k[200];

char secondmatch(){
    int l=0;
    FILE *fp;
    int i,j;
    FILE *fps = fopen("in.txt", "r");
    char c = fgetc(fps);
    while ( c != EOF )
    {
        c = fgetc(fps);
        if(c == '\n')
        {   l++; }
    }
    fclose(fps);
    char d[l][100];
    fp = fopen("in.txt", "r");
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
            break;
        }
    }
    char a='n';
    int t=0;
    for(t=0;t<i;t++){
        if(d[t][0]>='0' && d[t][0]<='9')
            a=d[t][0];
    }
    return a;
}

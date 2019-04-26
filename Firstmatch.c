#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"
extern data database[100];
extern char k[200];

int firstmatch(){
    char *c=(char *)malloc(100*sizeof(char));
    int count=1,e=0;
    int j=0;
    FILE *fp = fopen("data.txt", "rb" ) ;
    for(j=0;j<=1000;j++)
    {
        int r=1;
        count=1;
        
        while(count<=4)
        {
            if(fgets(c,1000 , fp)==NULL){
                e=1;
                break;
            }
            if(count%4 ==0)
            {
                database[j].input= c;
            }
            else if(count%4==1)
            {
                database[j].output1=c;
            }
            else if(count%4==2)
            {
                database[j].output2=c;
            }
            else if(count%4==3)
            {
                database[j].output3=c;
            }
            count++;
            c=(char *)malloc(100*sizeof(char));
            
            
        }
        if(e==1)
            break;
        if(database[j].input)
        {
            r=strcmp(database[j].input,k);
        }
        if(r==0)
        {
            return j;
        }
    }
    return 0;
}

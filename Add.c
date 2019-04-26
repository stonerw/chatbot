#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"
extern char bbq[100];
extern char garbage[100];

void addcon(int s){
    FILE *fps = fopen("data.txt", "r+");
    while(fgets(garbage, sizeof(garbage), fps) != NULL)
    {}
    if(s==1){
        printf("please enter your answer.\n");
        scanf(" % s",bbq);
        gets(bbq);
        fprintf(fps,"%s\n",bbq);
        fprintf(fps,"%s\n",bbq);
        fprintf(fps,"%s\n",bbq);
    }
    if(s==2){
        printf("please enter your first answer.\n");
        scanf(" % s",bbq);
        gets(bbq);
        fprintf(fps,"%s\n",bbq);
        fprintf(fps,"%s\n",bbq);
        printf("please enter your second answer.\n");
        scanf(" % s",bbq);
        gets(bbq);
        fprintf(fps,"%s\n",bbq);
    }
    if(s==3){
        printf("please enter your first answer.\n");
        scanf(" % s",bbq);
        gets(bbq);
        fprintf(fps,"%s\n",bbq);
        printf("please enter your second answer.\n");
        scanf(" % s",bbq);
        gets(bbq);
        fprintf(fps,"%s\n",bbq);
        printf("please enter your last answer.\n");
        scanf(" % s",bbq);
        gets(bbq);
        fprintf(fps,"%s\n",bbq);
    }
    printf("now please re-enter your question\n");
    scanf(" % s",bbq);
    gets(bbq);
    fprintf(fps,"%s\n",bbq);
    fclose(fps);
}

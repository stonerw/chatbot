//
//  main.c
//  new chatbot
//
//  Created by stoner on 2019/4/11.
//  Copyright © 2019 stoner. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *input;
    char *output1;
    char *output2;
    char *output3;
}data;
data database[100];
char k[200];

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

int getrand(){
    int a;
    srand((unsigned)time(NULL));
    a = rand();
    return a;
}

int firstmatch(){
    char *c=(char *)malloc(100*sizeof(char));
    int count=1,e=0;
    FILE *fp = fopen("data.txt", "rb" ) ;
    for(int j=0;j<=1000;j++)
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
char bbq[100];
char garbage[100];
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


int main() {
    char name[20];
    char a;
    printf("nice to meet you, what is your name?\n");
    for(;;){
        gets(name);
        if(cheakdirty(name)==1){
            printf("I'm making friends with you. Please be polite >-<.\n");
            printf("please re-enter your name.\n");
        }
        if(cheakdirty(name)==0){
            printf("Sir or Madam?(f for female, m for male)\n");
            scanf("%c",&a);
            if(a=='f'){
                printf("hello, Mrs.");
                for(int m=0;;m++){
                    printf("%c",name[m]);
                    if(name[m]=='\0')
                        break;
                }
            }
            if(a=='m'){
                printf("hello, Mr.");
                for(int m=0;;m++){
                    printf("%c",name[m]);
                    if(name[m]=='\0')
                        break;
                }
            }
            printf("\n");
            break;
        }
    }
    printf("please enter your conversation, enter 886 to exit，enter seek to searchingmode\n");
    gets(k);
    for(;;){
        for(;;){
            gets(k);
            if(dirtyw()==1){
                printf("please be polite. don't be so rude. say it in a friendly way.\n");
                break;
            }
            if(k[0]=='8'&&k[1]=='8'&&k[2]=='6'){
                printf("goodbye,bro. we had a nice time.\n");
                exit(0);
            }
            if(k[0]=='s'&&k[1]=='e'&&k[2]=='e'&&k[3]=='k'){
                for(;;){
                    printf("now please enter the sentence you want to match. press 0 to the main\n");
                    gets(k);
                    if (k[0]=='0'&&k[1]=='\0') {
                        break;
                    }
                    if(firstmatch()==0)
                        printf("the sentence is not in my sentence library.\n");
                    else
                        printf("the sentence is in the sentence library.\n");
                }
            }
            if((k[0]=='i'&&k[1]=='s')||(k[0]=='a'&&k[1]=='r'&&k[2]=='e')||(k[0]=='a'&&k[1]=='m')||(k[0]=='w'&&k[1]=='a'&&k[2]=='s')||(k[0]=='w'&&k[1]=='e'&&k[2]=='r'&&k[3]=='e')||(k[0]=='d'&&k[1]=='o'&&k[2]=='e'&&k[3]=='s')||(k[0]=='d'&&k[1]=='o')||(k[0]=='d'&&k[1]=='i'&&k[2]=='d'))
            {
                printf("absolutely，yes\n");
                break;
            }
            if(k[0]=='t'&&k[1]=='e'&&k[2]=='a'&&k[3]=='c'&&k[4]=='h'&&k[5]=='i'&&k[6]=='n'&&k[7]=='g'&&k[8]=='m'&&k[9]=='o'&&k[10]=='d'&&k[11]=='e'){
                printf("now enter the teaching mode\n");
                printf("you can enter up to three answers\n");
                printf("now select your answers number. 1 or 2 or 3\n");
                int s=0;
                scanf("%i",&s);
                addcon(s);
                printf("now your Q and A are successfully saved\n");
                break;
            }
            int v;
            for (v=0;;v++)
            {
                if(k[v]=='\0')
                {
                    k[v]='\n';
                    k[v+1]='\0';
                    break;
                }
            }
            if(firstmatch()>0){
                int x=firstmatch();
                if(getrand()%3==0)
                    printf("%s",database[x].output1);
                if(getrand()%3==1)
                    printf("%s",database[x].output2);
                if(getrand()%3==2)
                    printf("%s",database[x].output3);
            }
            if(firstmatch()==0){
                for (v=0;;v++){
                    if(k[v]=='\0'){
                        k[v-1]=' ';
                        break;
                    }
                }
                if(secondmatch()=='1'){
                    if(getrand()%3==0)
                        printf("The weather forecast is really incredible\n");
                    if(getrand()%3==1)
                        printf("The weather forecast is very accurate\n");
                    if(getrand()%3==2)
                        printf("maybe tomorrow will be a little hot\n");
                }
                else if(secondmatch()=='2'){
                    if(getrand()%3==0)
                        printf("Regular exercise is good for your health\n");
                    if(getrand()%3==1)
                        printf("I also often pay attention to sports games. My favorite team is SAN Antonio spurs in NBA\n");
                    if(getrand()%3==2)
                        printf("With the improvement of people's material level, more and more people begin to pay attention to sports\n");
                }
                else if(secondmatch()=='3'){
                    if(getrand()%3==0)
                        printf("Hello, long time no see\n");
                    if(getrand()%3==1)
                        printf("what's up ,bro\n");
                    if(getrand()%3==2)
                        printf("hi, nice to meet you\n");
                }
                else if(secondmatch()=='4'){
                    if(getrand()%3==0)
                        printf("Sounds like you have an interesting itinerary\n");
                    if(getrand()%3==1)
                        printf("The journey is always full of hard work and unknown\n");
                    if(getrand()%3==2)
                        printf("A quick trip with a friend can really take your mind off your problems\n");
                }
                else if(secondmatch()=='5'){
                    if(getrand()%3==0)
                        printf("No idle work, every work needs to pay sweat and time\n");
                    if(getrand()%3==1)
                        printf("We should respect every profession\n");
                    if(getrand()%3==2)
                        printf("Every profession has its own unique role, and society is like a big machine that needs every part to work together\n");
                }
                else if(secondmatch()=='6'){
                    if(getrand()%3==0)
                        printf("Stop talking about food. It's almost time for dinner. I'm hungry\n");
                    if(getrand()%3==1)
                        printf("Do you know there is a cantonese restaurant on chunxi road which serves very special dishes\n");
                    if(getrand()%3==2)
                        printf("Oh, forget about the food. I'm on a diet recently. Don't whet my appetite\n");
                }
                else if(secondmatch()=='7'){
                    if(getrand()%3==0)
                        printf("I usually buy things online\n");
                    if(getrand()%3==1)
                        printf("i love these little things in ikea\n");
                    if(getrand()%3==2)
                        printf("maybe tomorrow will be a little hot\n");
                }
                else if(secondmatch()=='8'){
                    if(getrand()%3==0)
                        printf("Computer is the most popular major nowadays\n");
                    if(getrand()%3==1)
                        printf("The development of computers is changing our way of life\n");
                    if(getrand()%3==2)
                        printf("You can talk to my inventor, stoner, who is a computer science student\n");
                }
                else if(secondmatch()=='9'){
                    if(getrand()%3==0)
                        printf("Oh, the person you mentioned seems to be a very famous singer or actor. Forgive my bad memory\n");
                    if(getrand()%3==1)
                        printf("We robots really don't know much about your human celebrities\n");
                    if(getrand()%3==2)
                        printf("Is the person you mentioned famous？\n");
                }
                else if(secondmatch()=='0'){
                    for(int t=0;;t++){
                        printf("%c",k[t]);
                        if(k[t]=='\0')
                            break;
                    }
                    printf("?\n");
                    printf("i don't know how to answer your question\n");
                    printf("you can enter 'teachingmode' to teach my how to answer your question.\n");
                }
            }
        }
    }
    return 0;
}

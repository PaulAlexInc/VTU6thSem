/*Program 9:
Design,  develop  and  implement  a  C/C++/Java  program  to implement  page  replacement  algorithms  LRU  and  FIFO. Assume suitable input required to demonstrate the results.

Code*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fifo(char [ ],char [ ], int, int);
void lru(char [ ],char [ ], int, int);

int main()
{
    int ch, choice = 1, i, l, f;
    char frame[10], s[25];
    printf("\nEnter the number of frames: \n"); 
    scanf("%d",&f);
    printf("\nEnter the string: \n");
    scanf("%s",s);
    l = strlen(s);
    for(i=0;i<f;i++)
        frame[i]=-1;
    do
    {
        printf("\n1:FIFO\n2:LRU\n3:Exit\n"); 
        printf("\nEnter your choice: \n"); 
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                for(i=0;i<f;i++)
                    frame[i]=-1;
                fifo(s,frame,l,f);
                break;
            case 2:
                for(i=0;i<f;i++)
                    frame[i]=-1;
                lru(s,frame,l,f);
                break;
            case 3:
                exit(0);
        }
        printf("\n\n\tDo you want to continue? If yes, press 1, else press 0 :"); 
        scanf("%d",&choice);
    }
    while(choice == 1);
    return(0);
}

void fifo(char s[], char frame[], int l, int f) 
{
    int i, j=0, k, flag=0, count=0;
    printf("\n\tPAGE\t FRAMES\t FAULTS");
    for(i=0;i<l;i++) 
    {
        for(k=0;k<f;k++)
        {
            if(frame[k]==s[i])
                flag=1;
        }
        if(flag==0)
        {
            printf("\n\t%c\t",s[i]);
            frame[j]=s[i];
            j++;
            for(k=0;k<f;k++) 
                printf(" %c",frame[k]); 
            printf("\tFault %d",count);
            count++;
        }
        else
        {
            flag=0;
            printf("\n\t%c\t",s[i]);
            for(k=0;k<f;k++) 
            {
                printf(" %c",frame[k]); }
                printf("\tHit");
            }
            if(j==f)
                j=0; 
        }
}



void lru(char s[], char frame[], int l, int f) 
{
    int i, j=0, k, m, flag=0, count=0, top=0;
    printf("\n\tPAGE\t FRAMES\t FAULTS");
    for(i=0;i<l;i++) 
    {
        for(k=0;k<f;k++)
        {
            if(frame[k]==s[i]) 
            {
                flag=1;
                break;
            }
        }
        printf("\n\t%c\t",s[i]);
        if(j!=f && flag!=1)
        {
            frame[top]=s[i];
            j++;
            if(j!=f)
                top++;
        }
        else
        {
            if(flag!=1) 
            {
                for(k=0;k<top;k++) 
                    frame[k]=frame[k+1]; 
                frame[top]=s[i];
            }
            if(flag==1) 
            {
                for(m=k;m<top;m++) 
                    frame[m]=frame[m+1]; 
                frame[top]=s[i];
            }
        }
        for(k=0;k<f;k++)
        {
            printf(" %c",frame[k]); }
            if(flag==0)
            {
                printf("\tFault %d",count);
                count++;
            }
            else
                printf("\tHit");
            flag=0;
        }
}


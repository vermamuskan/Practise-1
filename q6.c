#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void squeeze(char s1[1000],char s2[1000]);
void main(){
char s1[1000],s2[1000];
printf("enter 1st string");
gets(s1);
printf("\nenter 2nd string");
gets(s2);
squeeze(s1,s2);
printf("%s",s1);
}
void squeeze(char s[1000],char t[1000]){
   int i,j,k;
    k=0;

    for(i=0;s[i]!='\0';++i)
    {
        for(j=0; (s[i]!=t[j]) && t[j]!='\0' ;++j)
            ;
        if(t[j]=='\0')
            s[k++] = s[i];
    }
    
    s[k]='\0';
}

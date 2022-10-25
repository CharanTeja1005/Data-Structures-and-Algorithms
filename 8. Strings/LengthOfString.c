#include<stdio.h>
#include<string.h>

int main()
{
    char *s = "Welcome";
    int i;
    for(i=0;s[i]!='\0';i++){}
    printf("Length of String : %d",i);
    return 0;
}
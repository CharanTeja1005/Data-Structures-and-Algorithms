#include<stdio.h>

int validate(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(!(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 48 && s[i] <= 57))
            return 0;
    }
    return 1;
}

int main()
{
    char *s1 = "Charan@123";
    char *s2 = "Charan123";
    validate(s1) ? printf("String is valid\n") : printf("String is not valid\n");
    validate(s2) ? printf("String is valid\n") : printf("String is not valid\n");
    return 0;
}
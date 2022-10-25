#include<stdio.h>

char* toLower(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        s[i] += 32;
    }
    return s;
}

char* changeCase(char* s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    return s;
}

int main()
{
    char s1[] = "WELCOME";
    char s2[] = "WeLcOmE5";
    printf("%s\n",toLower(s1));
    printf("%s\n",changeCase(s2));
    return 0;
}
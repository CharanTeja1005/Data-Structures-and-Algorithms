#include<stdio.h>
#include<stdlib.h>

void swap(char *a,char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

char *reverse1(char *s)
{
    int i,j;
    char *r = (char *)malloc(20 * sizeof(char));
    for(i=0;s[i]!='\0';i++){}
    i -= 1;
    for(j=0;i>=0;i--,j++)
    {
        r[j] = s[i];
    }
    r[j] = '\0';
    return r;
}

char *reverse2(char *s)
{
    int i,j;
    for(j=0;s[j]!='\0';j++){}
    j -= 1;
    for(i=0;i<j;i++,j--)
    {
        swap(&s[i],&s[j]);
    }
    return s;
}

int main()
{
    char s[] = "Charan";
    printf("%s\n",reverse1(s));
    printf("%s\n",reverse2(s));
    return 0;
}
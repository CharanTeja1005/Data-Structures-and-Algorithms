#include<stdio.h>

void anagram(char *a,char *b)
{
    int H[26] = {0};
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        H[a[i] - 97]++;
    }
    for(i=0;b[i]!='\0';i++)
    {
        H[b[i] - 97]--;
        if(H[b[i]-97] < 0)
        {
            printf("Not Anagram\n");
            return;
        }
    }
    printf("Anagram\n");
}

int main()
{
    char *a = "verbose";
    char *b = "observe";
    anagram(a,b);
    return 0;
}
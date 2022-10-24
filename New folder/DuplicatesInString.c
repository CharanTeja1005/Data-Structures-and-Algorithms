#include<stdio.h>

void duplicates(char *A)
{
    char H[26] = {0};
    for(int i=0;A[i]!='\0';i++)
    {
        H[A[i] - 97]++;
    }
    for(int i=0;i<26;i++)
        if(H[i] > 1)
            printf("%c is appearing %d times\n",i+97,H[i]);
}

int main()
{
    char *A = "findings";
    duplicates(A);
    return 0;
}
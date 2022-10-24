#include<stdio.h>
#include<stdlib.h>

int compare(char *a,char *b)
{
    int i,j;
    for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++)
    {
        if(a[i] != b[j])
            break;
    }
    if(a[i] == b[j])
        return 0;
    else
        return a[i] - b[j];
}

char *reverse(char *s)
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

int palindrome(char *s)
{
    int i,j;
    for(j=0;s[j]!='\0';j++){}
    j -= 1;
    for(i=0;i<j;i++,j--)
    {
        if(s[i] != s[j])
            return 0;
    }
    return 1;
}

int main()
{
    char *a = "Painter";
    char *b = "Painting";
    char *s = "madam";
    int c = compare(a,b);
    if(c == 0)
        printf("Equal\n");
    else if(c < 0)
        printf("Smaller\n");
    else
        printf("Greater\n");
    printf("%s\n",reverse(s));
    if(compare(reverse(s),s) == 0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    palindrome(s) ? printf("Palindrome\n") : printf("Not Palindrome\n");
    return 0;
}
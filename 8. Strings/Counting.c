#include<stdio.h>

int main()
{
    char *s = "Hello How are   you";
    int vowels = 0;
    int consonants = 0;
    int words = 1;
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] ==  'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            vowels++;
        else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            consonants++;
        if(s[i] == ' ' && s[i-1] != ' ')
            words++;
    }
    printf("Vowels : %d\n",vowels);
    printf("Consonants : %d\n",consonants);
    printf("Words: %d\n",words);
    return 0;
}
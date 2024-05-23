
//Verifica se uma palavra ou frase forma um palindromo, ignorando os espaços.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 99

int compare(char palavra[])
{
    int a = 0, b = strlen(palavra)-2;
    while(a <= b)
    {
        printf("a:%c|%d b: %c|%d\n", palavra[a], a, palavra[b], b);
        if (palavra[a] == ' ')
        {
            a++;
        }
        else if(palavra[b]  == ' ')
        {
            b--;
        }
        else if (tolower(palavra[a]) != tolower(palavra[b]))
        {
            return 0;
        }
        else
        {
            a++;
            b--;
        }
    }
    return 1;
}

int main(void)
{
    char word[MAX];
    fgets(word, MAX, stdin);
    printf("%d\n", compare(word));
}

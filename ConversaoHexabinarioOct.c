#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Crie uma função para converter inteiros decimais em binários, octais ou
hexadecimais. A função deve receber como parâmetro o inteiro a ser
convertido, um caractere que indica o tipo da conversão e uma string que
receberá o resultado final da conversão. Se o caractere que indica o tipo de
conversão for ‘b’, converta o inteiro para um binário, se for ‘o’, converta-o
para octal e se ‘h’, converta-o para hexadecimal. A função deve gerar uma
string com o resultado da conversão, a qual deve ser copiada no parâmetro
do tipo string passado como parâmetro. O argumento desse parâmetro
deve ser inicialmente vazio. Teste sua função através da função main do
programa. Não utilize strings de controle, tais como %o e%h para essa
conversão, e sim o método de divisões sucessivas da base (dividendo),
onde os restos e o último dividendo formam o número de trás para frente*/



#define MAX 99

int change(int num, char op, char string[]);

int main()
{
    int num;
    char d, saida[MAX];
    printf("numero em decimal: ");
    scanf("%d", &num);
    printf("Deseja converter para qual base?: \n[b]inario:\n[o]ctal\n[h]exadecimal\n");
    scanf(" %c", &d);
    if (change(num, d, saida) == 1)
    {
        printf("ERROR!");
    }
    else
    {
        printf("%s\n", saida);
    }

}

int change(int num, char op, char string[])
{
    int i = 0, base;
    char texto[MAX];
    switch (op)
    {
    case 'b':
        base = 2;
        break;
    case 'o':
        base = 8;
        break;
    case 'h':
        base = 16;
        break;
    default:
        return 1;
    }
    //pega os restos em decimal (tem que inverter agora e converter pra base certa)
    while (texto[i] != num)
    {
        texto[i] = (num%base)+48; //adiciona 48 para converter de int para char
        num = num/base;
        i++;
        
        if (num < base)
        {
            texto[i] = num+48;
            break;
        }
    }
    int h = strlen(texto)-1; //-1 para pegar o indice do ultimo elemento
    i = 0;
    while (h >= 0)
    {
     if (op == 'b' || op == 'o')
     {
        string[i] = texto[h];
     }
     else
     {
        if ((texto[h]-48) < 10)
        {
            string[i] = texto[h];
        }
        else
        {
            string[i] = texto[h]+7; //adiciona 7 para converter para hexa
        }
     }
    i++;
    h--;
    string[i] = '\0'; //adiciona 0 no final para marcar o fim da string
    }
}
